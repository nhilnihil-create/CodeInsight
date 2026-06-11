#include <iostream>
#include <string>
using namespace std;
 
class Node{
public:
    Node* prev;
    Node* next;
    int value;
};
 
class DoublyLinkedList{
private:
    Node* first;
    Node* last;
public:
    DoublyLinkedList(){
        first = NULL;
        last = NULL;
    }
    void Insert(int x);
    void Delete(int x);
    void DeleteFirst();
    void DeleteLast();
    void PrintAll();
};
 
void DoublyLinkedList::Insert(int x){
    Node* node = new Node();
    node->value = x;
     
    if(first == NULL){
        first = node;
        node->prev = first;
        node->next = first;
    }else{
        node->prev = first->prev;
        node->next = first;
        first->prev->next = node;
        first->prev = node;
        first = node;
    }
}
 
void DoublyLinkedList::Delete(int x){
    Node* cur = first;
    if(cur==NULL)return;
    do{
        if(cur->value == x){
            if(cur == first){
                if(cur->next == first){
                    first = NULL;
                }else{
                    cur->next->prev = cur->prev;
                    cur->prev->next = cur->next;
                    first = cur->next;
                }
            }else{
                cur->next->prev = cur->prev;
                cur->prev->next = cur->next;
            }
            break;
        }
         
        cur = cur->next;
    }while(cur != first);
}
 
void DoublyLinkedList::DeleteFirst(){
    if(first != NULL){
        if(first->next == first){
            first = NULL;
        }else{
            first->next->prev = first->prev;
            first->prev->next = first->next;
            first = first->next;
        }
    }
}
 
void DoublyLinkedList::DeleteLast(){
    if(first != NULL){
        if(first->next == first){
            first = NULL;
        }else{
            first->prev = first->prev->prev;
            first->prev->next = first;
        }
    }
}
 
void DoublyLinkedList::PrintAll(){
    Node* cur = first;
    if(cur == NULL)return;
    do{
        cout << (cur->value);
        cur = cur->next;
    }while(cur != first && cur != NULL && (cout<<" "));
    cout << "\n";
}
 
int main() {
    DoublyLinkedList list = DoublyLinkedList();
    int n,i,x;
    string com;
	
	cin.tie(0);
	ios::sync_with_stdio(false);
     
    for(cin>>n,i=n;i;--i){
        cin>>com;
         
        if(com == "insert"){
            cin>>x;
            list.Insert(x);
        }else if(com == "delete"){
            cin>>x;
            list.Delete(x);
        }else if(com == "deleteFirst"){
            list.DeleteFirst();
        }else if(com == "deleteLast"){
            list.DeleteLast();
        }
    }
    list.PrintAll();
     
    return 0;
}