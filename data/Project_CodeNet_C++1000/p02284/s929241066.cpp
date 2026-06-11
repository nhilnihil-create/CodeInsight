#include<iostream>
#include<cstring>
using namespace std;

struct Node{//binary tree's node
    int key;
    Node *parent, *left, *right;
};

Node *root, *NUL;

void insert(int node){
    //Now Searching...
    Node *nowNode = root;//start with root
    Node *nowParent = NUL;//root node's parent node is NULL
    while(nowNode!=NUL){
        if(nowNode->key<node){
            nowParent = nowNode;
            nowNode = nowParent -> right;
        }else{
            nowParent = nowNode;
            nowNode = nowNode -> left;
        }
    }
    //Now Creating new Node
    Node *newNode = new Node();
    newNode->key = node;
    newNode->left = newNode->right = NUL;
    //Now Inserting
    if(nowParent==NUL){//empty tree's root node
        root = newNode;
    }else if(node<nowParent->key){
        nowParent->left = newNode;
    }else{
        nowParent->right = newNode;
    }
}

void preOrder(Node *nowNode){
    if(nowNode==NUL) return;
    cout<<' '<<nowNode->key;
    preOrder(nowNode->left);
    preOrder(nowNode->right);
}

void inOrder(Node *nowNode){
    if(nowNode==NUL) return;
    inOrder(nowNode->left);
    cout<<' '<<nowNode->key;
    inOrder(nowNode->right);
}

bool find(int toFind, Node *nowNode){
    //cout<<"-- now finding :"<<nowNode->key<<endl;
    if(nowNode==NUL) return false;
    if(nowNode->key == toFind) return true;
    if(toFind>nowNode->key){
        return find(toFind, nowNode->right);
    }else{
        return find(toFind, nowNode->left);
    }
}

int main(){
    root = NUL;//initial root
    int ope;
    cin>>ope;
    for(int i=0; i<ope; i++){
        string op;
        int toInsert;
        int toFind;
        cin>>op;
        if(op=="print"){
            inOrder(root);
            cout<<endl;
            preOrder(root);
            cout<<endl;
        }else if(op=="insert"){
            cin>>toInsert;
            insert(toInsert);
        }else{
            cin>>toFind;
            if(find(toFind, root)){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }
        }
    }
    return 0;
}

