#include <iostream>
#include <stdio.h>
#define MAX 100005
#define NIL -1

struct Node {
    int parent, left, right;
};

Node T[MAX];
int n, D[MAX];

void rec(int u, int p) {
    D[u] = p;
    if (T[u].right != NIL) rec(T[u].right, p);
    if (T[u].left  != NIL) rec(T[u].left, p+1);
}

void printChildren (int id) {
    printf("node %d: parent = %d, depth = %d, ", id, T[id].parent, D[id]);
    if (T[id].left != NIL || T[id].parent == NIL) {
        if (T[id].parent == NIL) printf("root, [");
        else printf("internal node, [");
        int pri_ch = T[id].left;
        while (pri_ch != NIL) {
            printf("%d", pri_ch);
            pri_ch = T[pri_ch].right;
            if (pri_ch != NIL) printf(", ");
        }
        printf("]");
    } else {
        printf("leaf, []");
    }
    printf("\n");
}


int main() {
    int id;
    int num_ch;
    int ch_id;
    int left = 0;
    int root = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id, &num_ch);
        for (int j = 0; j < num_ch; j++) {
            scanf("%d", &ch_id);
            if(j==0) T[id].left = ch_id;
            else T[left].right = ch_id;
            left = ch_id;
            T[ch_id].parent = id;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (T[i].parent == NIL) root = i;
    }
    
    rec(root, 0);
    for (int i = 0; i < n; i++) {
        printChildren(i);
    }
    
    return 0;
}