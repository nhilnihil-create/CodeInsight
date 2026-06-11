#include <bits/stdc++.h>
//#include <iostream>
//#include <stdlib.h>
//#include <string>
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

int main(){
  int i,n,x;
  string comment;
  cin >> n;
  for(i = 0; i < n; i++){
    cin >> comment;
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
}

void insert(int k){
  Node *y = NIL;
  Node *x = root;
  Node *z;

  //z = (Node*)malloc(sizeof(Node));
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
}

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
}