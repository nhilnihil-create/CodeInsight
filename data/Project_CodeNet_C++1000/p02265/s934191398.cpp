#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node *prev,*next;
};


struct Node *nil;//node???????????¨????°?

void trace(){
    struct Node *n;
    n=nil->next;
    cout << n->key;
    n = n->next;
    while(n!=nil){
        cout<<" "<<n->key;
        n = n->next;
        if(n==nil)break;
    }
    cout << endl;
}

void init(){
    nil =(struct Node *)malloc(1*sizeof(struct Node));
    nil->prev = nil;
    nil->next = nil;
}

void insert(int key){
    struct Node *node = (struct Node *)malloc(1*sizeof(struct Node));
    node -> key = key;
    node -> next = nil->next;
    nil->next->prev = node;
    nil->next = node;
    node -> prev = nil;
    //trace();
}

void deleteNode(struct Node* node){
    if(node==nil)return;
    /*??????????????????????????????????????¨?????????????????????*/
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

struct Node* listSearch(int key) {
    struct Node *n = nil->next;
    while(n != nil && n->key != key ) {
        n = n-> next;
    }
    return n;
}

void deleteKey(int key) {
    deleteNode(listSearch(key));
    //trace();
}

// void deleteKey(int key){
//     struct Node *n;
//     n = nil->next;
//     while(n->key!=key && n!=nil){
//         //cout << "??°???" << n << endl;
//         n = n->next;
//         //cout << "??°??????" << n << endl;
        
//     }
//     delete(n);
//     trace();
// }




int main(){
    init();
    int n,key;
    string command;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> command;
        if(command=="insert"){
            cin >> key;
            insert(key);
        }else if(command=="delete"){
            cin >> key;
            deleteKey(key);           
        }else if(command=="deleteFirst"){
            deleteFirst();
            continue;
        }else if(command=="deleteLast"){
            deleteLast();
            continue;
        }
    }
    
    trace();
    
    return 0;
}