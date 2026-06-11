#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;
struct Node {
  Node *prev,*next;
  int key;
};
Node *Nil;
void init(){
  Nil=(Node *)malloc(sizeof(Node));
  Nil->next=Nil;
  Nil->prev=Nil;
}

void Insert(int x){
  Node *node;
  node=(Node *)malloc(sizeof(Node));
  node->key=x;
  node->next=Nil->next;
  Nil->next->prev=node;
  node->prev=Nil;
  Nil->next=node;
}
Node* listsearch(int x){
  Node *del = Nil->next;
  while(del!=Nil && del->key!=x){
    del=del->next;
  }
  return del;
}
void DeleteNode(Node *node){
  if(node==Nil)return ;
  node->prev->next=node->next;
  node->next->prev=node->prev;
  free(node);
  
}
void DeleteFirst(){
  DeleteNode(Nil->next);
}
void DeleteLast(){
  DeleteNode(Nil->prev);
  
}
void print_list(){
  
  Node *node;
  node=Nil->next;
  while(node!=Nil){
    printf("%d",node->key);
    if(node->next!=Nil)printf(" ");
    node=node->next;
  }
  printf("\n");
}
int main(){
  int n;
  string s;
  int x;
  scanf("%d",&n);
  init();
  for(int i=0;i<n;i++){
    cin >> s;
    if(s[0]=='i'){cin >> x;Insert(x);}
    else if(s[0]=='d'){
      if(s.length()==6){cin >> x; DeleteNode(listsearch(x));}
      else if(s.length()==11)DeleteFirst();
      else if(s.length()==10)DeleteLast();
    }
  }
  print_list();
  return 0;
}