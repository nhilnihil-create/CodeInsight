#include <bits/stdc++.h>
using namespace std;

struct Node{
  int key;
  Node *right;
  Node *left;
  Node *parent;
};

Node *NIL;
Node *root;
void insert(int);
void inorder(Node*);
void preorder(Node*);
Node* find(Node*,int);

int main(){
  int i,n,x;
  string comment;
  Node* t;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> comment;
    if(comment[0] == 'f'){
      cin >> x;
      t = find(root, x);
      if( t != NIL){
        cout << "yes" << endl;
      }
      else{
        cout << "no" << endl;
      }
    }
    if(comment == "insert"){
      cin >> x;
      insert(x);
    }
    else if(comment == "print"){
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
  }
  return 0;
}//END main function


void insert(int k){
  Node *y = NIL;
  Node *x = root;
  Node *z;
  z = new Node;
  z->key = k;
  z->left = NIL;
  z->right = NIL;
  
  while(x != NIL){
    y = x;
    if((z->key) < (x->key)){
      x = x->left;
    }
    else{
      x = x->right;
    }
  }
  z->parent = y;
  if(y == NIL){
    root = z;
  }else{
    if((z->key) < (y->key)){
      y->left = z;
    }
    else{
      y->right = z;
    }
  }
}//END insert function


void inorder(Node *u){
  if(u == NIL){
    return;
  }
  inorder(u->left);
  cout << " " << u->key;
  inorder(u->right);
}

void preorder(Node *u){
  if(u == NIL){
    return;
  }
  cout << " " << u->key;
  preorder(u->left);
  preorder(u->right);
}//END inorder function


Node* find(Node* u,int k){
  while(u != NIL && k != u->key){
    if(k < (u->key)){
      u = u->left;
    }
    else{
      u = u->right;
    }
  }
  return u;
}//END find function