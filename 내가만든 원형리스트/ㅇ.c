#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

void print_list(ListNode* head)
{
    ListNode* p;
    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }
    p = head->link;
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != head);
    if (head != head->link)
        printf("%d ->", p->data);
    /*while (p != head) {
       printf("%d -> ", p->data);
       p = p->link;
    }
    printf("%d -> ",p->data);
    */
    printf("\n");
}
ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL)
    {
        head = node;
        node->link = node;
    }
    else
    {
        node->link = head->link;
        head->link = node;
    }
    return head; // head가 시작점을 가리키기 때문에 head를 반환함 node (x)
}
ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL)
    {
        head = node;
        node->link = node;
    }
    else
    {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}
ListNode* delete_first(ListNode* head)
{
    ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        removed = head->link;
        head->link = removed->link;
        if (removed == head)
            head = NULL;
        free(removed);
    }
    return head;
}
ListNode* delete_last(ListNode* head)
{
    ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (head->link == head) {
        free(head);
        head = NULL;
    }
    else
    {
        removed = head;
        while (removed->link != head)
        {
            removed = removed->link;
        }
        removed->link = head->link;
        head = removed;

    }

    return head;

}


int main(void) {
    ListNode* head = NULL;
    int choice;
    int data;

    while (1) {
        printf("xxxxx MENU xxxxx\n");
        printf("(1) Insert First\n");
        printf("(2) Insert Last\n");
        printf("(3) Delete First\n");
        printf("(4) Delete Last\n");
        printf("(5) Print List\n");
        printf("(0) Exit\n");
        printf("Enter the menu: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Input a number: ");
            scanf("%d", &data);
            head = insert_first(head, data);
            break;
        case 2:
            printf("Input a number: ");
            scanf("%d", &data);
            head = insert_last(head, data);
            break;
        case 3:
            head = delete_first(head);
            printf("First node has been deleted\n");
            break;
        case 4:
            head = delete_last(head);
            printf("Last node has been deleted\n");
            break;
        case 5:
            print_list(head);
            break;
        case 0:
            printf("Exit the Program.\n");
            exit(0);
        default:
            printf("주어진 메뉴에서 선택하세요\n");
        }
        printf("\n");
    }
    return 0;
}