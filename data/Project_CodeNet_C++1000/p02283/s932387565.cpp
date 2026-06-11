#include<bits/stdc++.h>
using namespace std;
  
struct Node{
  int key;
  Node *right,*left,*p;
};
  
Node *NIL,*root;
  
void insert(int k){
  Node *x=root;
  Node *y=NIL;
  Node *T;
    
  T=(Node *)malloc(sizeof(Node));
  T->key=k;
  T->left=NIL;
  T->right=NIL;
    
  while(x!=NIL){
    y=x;
    if(T->key<x->key) x=x->left;
    else x=x->right;  
  }
  T->p=y;
  if(y==NIL) root=T;
  else if(T->key<y->key) y->left=T;
  else y->right=T;
}
  
void in(Node *T){
  if(T!=NIL){
    in(T->left);
    cout<<' '<<T->key;
    in(T->right);
  }
} 
 
void pre(Node *T){
  if(T!=NIL){
    cout<<' '<<T->key;
    pre(T->left);
    pre(T->right);
  }
}
  
int main(){
  int m,k;
  string str;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>str;
    if(str[0]=='i'){
      cin>>k;
      insert(k);
    }
    else {
      in(root);
      cout<<endl;
      pre(root);
      cout<<endl;
    }
  }
  return 0;
}

