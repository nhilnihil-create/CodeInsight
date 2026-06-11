/*Rooted Trees*/

#include <iostream>
#include <cstdio>
#define MAX 100005
#define NIL -1
using namespace std;

struct Node {
    int parent;
    int left;
    int right;
};

Node Tree[MAX];
int D[MAX];

void print(int u) {
    printf("node %d: ",u);
    printf("parent = %d, ",Tree[u].parent);
    printf("depth = %d, ",D[u]);
    if (Tree[u].parent==NIL) {
        printf("root, ");
    } else if (Tree[u].left==NIL) {
        printf("leaf, ");
    } else {
        printf("internal node, ");
    }
    printf("[");
    int c;
    for (int i=0,c=Tree[u].left; c!=NIL; i++,c=Tree[c].right) {
        if (i) {
            printf(", ");
        }
        printf("%d",c);
    }
    printf("]\n");
}
int rec(int u,int p) {
    D[u]=p;
    if (Tree[u].right!=NIL) {
        rec(Tree[u].right,p);
    }
    if (Tree[u].left!=NIL) {
        rec(Tree[u].left,p+1);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        Tree[i].parent=Tree[i].left=Tree[i].right=NIL;
    }
    for (int i=0; i<n; i++) {
        int v, d;
        cin >> v >> d;
        int l;
        for (int j=0; j<d; j++) {
            int c;
            cin >> c;
            if (j==0) {
                Tree[v].left=c;
            } else {
                Tree[l].right=c;
            }
            l=c;
            Tree[c].parent=v;
        }
    }
    int r;
    for (int i=0; i<n; i++) {
        if (Tree[i].parent==NIL) {
            r=i;
        }
    }
    rec(r,0);
    for (int i=0; i<n; i++) {
        print(i);
    }
    return 0;
}