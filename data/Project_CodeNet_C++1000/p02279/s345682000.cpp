#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
#define int(x) int x; scanf("%d",&x)
#define input(x) scanf("%d",&x)
#define rep(x,n) for(int x = 0; x < n; x++)
#define _br printf("\n")
#define INF 2000000000
#define NIL -1

//left child,right brother.

struct Node{
    int d;
    int p;
    int l;
    int r;
};

int n;
Node *T;

void input_data(){
    input(n);
    T = new Node[n];
    rep(i,n){
        T[i].d = NIL;
        T[i].p = NIL;
        T[i].l = NIL;
        T[i].r = NIL;
    }
    
    rep(i,n){
        int(id);int(num);
        int *ch;
        
        if (num != 0) {
            ch = new int[num];
            rep(k,num){
                input(ch[k]);
            }
            T[id].l = ch[0];
            T[ch[0]].p = id;
        }
        
        for (int k = 1; k < num; k++) {
            T[ch[k-1]].r = ch[k];
            T[ch[k]].p = id;
        }
        if (num != 0) delete [] ch;
    }
}

void deci_depth(int i, int de){
    T[i].d = de;
    if (T[i].l != NIL) deci_depth(T[i].l,de+1);
    if (T[i].r != NIL) deci_depth(T[i].r,de);
}

int ret_root(){
    int i = 0;
    while (T[i].p != NIL) {
        i = T[i].p;
    }
    return i;
}

void Node_type(int i, int root){
    if (i == root) {
        printf("root, ");
    }else if(T[i].l == NIL){
        printf("leaf, ");
    }else{
        printf("internal node, ");
    }
}

void print_child(int i){
    printf("[");
    if (T[i].l != NIL) {
        i = T[i].l;
        printf("%d",i);
        while (T[i].r != NIL) {
            i = T[i].r;
            printf(", %d",i);
        }
    }
    printf("]");
}

int main(){
    
    input_data();
    int root = ret_root();
    deci_depth(root,0);
    
    rep(i,n){
        printf("node %d: parent = %d, depth = %d, ",i,T[i].p,T[i].d);
        Node_type(i,root);
        print_child(i);
        _br;
    }
    
    return 0;
}