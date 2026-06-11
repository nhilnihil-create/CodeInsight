#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

struct Node
{
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;
    
    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = x;

    if(y==NIL) root = z;
    else if(z->key < y->key) y->left = z;
    else y->right = z;

}

void preOrder(Node *u){
    if(u == NIL) return;
    cout << " " << u->key;
    preOrder(u->left);
    preOrder(u->right);
}

void inOrder(Node *u){
    if(u == NIL) return;
    inOrder(u->left);
    cout << " " << u->key;
    inOrder(u->right);
}

int main(){
    int n,i,x;
    string com;

    cin >> n;
    
    for(int i=0;i<n;++i){
        cin >> com;
        if(com == "insert"){
            cin >> x;
            insert(x);
        } else if( com == "print"){
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }
}
