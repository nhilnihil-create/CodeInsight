#include <iostream>
#include <stdio.h>
#include <malloc.h>
#define MAXV 500000
using namespace std;

struct Node
{
    int key;
    Node *parent,*right,*left;
};
Node *root = NULL;
void inserts(int key)
{
    Node *z,*y,*x;
    z = (Node*)malloc(sizeof(Node));
    z->key = key;
    z->left = z->parent = z->right = NULL;
    y = NULL;
    x = root;
    while(x!=NULL)
    {
        y = x;
        if(x->key < z->key)
            x = x->right;
        else
            x = x->left;
    }
    z->parent = y;
    if(y==NULL){
        root = z;
    }
    else if(z->key < y->key){
        y->left = z;
    }
    else {
        y->right = z;
    }
}
void preParse(Node *x){
    if(x==NULL){
        return ;
    }
    printf(" %d",x->key);
    preParse(x->left);
    preParse(x->right);
}
void inParse(Node *x){
    if(x==NULL){
        return;
    }
    inParse(x->left);
    printf(" %d",x->key);
    inParse(x->right);
}
void print(){
    inParse(root);
    putchar('\n');
    preParse(root);
    putchar('\n');
}
int finda(int key){
    Node *x,*y = root;
    x = (Node*)malloc(sizeof(Node));
    x->key = key;
    x->left = x->parent = x->right = NULL;
    while(y!=NULL){
        if(x->key<y->key)
            y = y->left;
        else if(x->key>y->key)
            y = y->right;
        else if(x->key==y->key)
            return 1;
    }
    return 0;
}
int main()
{
    int m,key,i;
    char com[7];
    scanf("%d",&m);
    for(i = 0; i < m; i++)
    {
        scanf("%s",&com);
        if(com[0]=='i')
        {
            scanf("%d",&key);
            inserts(key);
        }
        else if(com[0]=='p')
        {
            print();
        }
        else if(com[0]=='f'){
            scanf("%d",&key);
            if(finda(key))printf("yes\n");
                else printf("no\n");
        }
    }
    return 0;
}

