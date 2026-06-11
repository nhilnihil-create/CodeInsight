#include<iostream>
#include<cstdio>
#include<queue>
#define NIL (-1)

using namespace std;

struct node{
    int parent, left, right, key;
}T[500001];
int SIZE, root = NIL;

void preorder(int i){
    if(i == -1)
        return;
    printf(" %d",T[i].key);
    if(T[i].left >= 0)
        preorder(T[i].left);
    if(T[i].right >= 0)
        preorder(T[i].right);
}

void inorder(int i){
    if(i == -1) return;
    if(T[i].left >= 0)
        inorder(T[i].left);
    printf(" %d",T[i].key);
    if(T[i].right >= 0)
        inorder(T[i].right);   
}

void insert(int key){
    int x = root, y = NIL;
    while(x != NIL){
        y = x;
        x = key < T[x].key ? T[x].left : T[x].right;
    }
    T[SIZE].parent = y;

    if(y == NIL)
        root = SIZE;
    else if(key < T[y].key)
        T[y].left = SIZE;
    else
        T[y].right = SIZE;
    T[SIZE].left = NIL;
    T[SIZE].right = NIL;
    T[SIZE].key = key;
    SIZE++;
}

int main(void){
    int m;
    cin >> m;
    while(m--){
        char s[10];
        cin >> s;
        if(s[0] == 'i'){
            int key;
            scanf("%d",&key);
            insert(key);
        }else{
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }
    return 0;
}
