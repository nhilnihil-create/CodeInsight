#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Node {
  int key;
  Node *next, *prev;
};

Node *nil;

Node* listSearch(int key) {
  Node *cur=nil->next;
  while (cur!=nil && cur->key!=key) {
    cur=cur->next;
  }
  return cur;
}
void init() {
  nil=(Node *)malloc(sizeof(Node));
  nil->next=nil;
  nil->prev=nil;
}
void printList() {
  Node *cur=nil->next;
  int isf=0;
  while (true) {
    if (cur==nil) {
      break;
    }
    if (isf++>0) {
      cout<<" "<<flush;
    }
    cout<<cur->key<<flush;
    cur=cur->next;
  }
  cout<<endl;
}
void deleteNode(Node *t) {
  if (t==nil) {
    return;
  }
  t->prev->next=t->next;
  t->next->prev=t->prev;
  free(t);
}
void deleteFirst() {
  deleteNode(nil->next);
}
void deleteLast() {
  deleteNode(nil->prev);
}
void deleteKey(int key) {
  deleteNode(listSearch(key));
}
void insert(int key) {
  Node *x=(Node *)malloc(sizeof(Node));
  x->key=key;
  x->next=nil->next;
  nil->next->prev=x;
  nil->next=x;
  x->prev=nil;
}
int main() {
  int n;
  cin>>n;
  init();
  char s[20];
  int key;
  for (int i=0; i<n; i++) {
    scanf("%s",s);
    if (!strcmp(s,"insert")) {
      scanf("%d",&key);
      insert(key);
    } else if (!strcmp(s,"delete")) {
      scanf("%d",&key);
      deleteKey(key);
    } else if (!strcmp(s,"deleteFirst")) {
      deleteFirst();
    } else {
      deleteLast();
    }
  }
  printList();
  return 0;
}

