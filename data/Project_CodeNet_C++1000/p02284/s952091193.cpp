#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


struct Node{
    int key;
    Node *parent, *right, *left;
};

Node *root, *NIL;


void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;
    z = (Node*)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;
    while(x!=NIL){
        y = x;
        if(x->key > z->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if(y==NIL) root = z;
    else {
        if(y->key > z->key) y->left = z;
        else y->right = z;
    }
}

void preorder(Node *u){
    if(u==NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}


void inorder(Node *u){
    if(u==NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void postorder(Node *u){
    if(u==NIL) return;
    postorder(u->right);
    postorder(u->left);
    printf(" %d", u->key);
}

Node *find_k(int k){
    Node *x = root;
    while(x!=NIL && x->key!=k){
        if(k < x->key) x = x->left;
        else if(k > x->key) x = x->right;
    }
    return x;
}

void findprint(Node *x){
    if(x==NIL) printf("no\n");
    else printf("yes\n");
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int k;
        string str;
        cin>>str;
        if(str=="insert"){
            scanf("%d", &k);
            insert(k);
        }
        else if(str=="find"){
            scanf("%d", &k);
            //cout<<endl;
            findprint(find_k(k));
        }
        else{
            inorder(root);
            cout<<endl;
            preorder(root);
            cout<<endl;
        }
    }
}


