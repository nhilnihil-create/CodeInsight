#include <cstdio>
#include <iostream>
using namespace std;
#define NIL -1
#define MAX 100005

struct Node {
    int parent, left, right, depth;
};

int n;
Node T[MAX];

void rec(int i, int d) {
    T[i].depth = d;
    if (T[i].right != NIL) rec(T[i].right, d);
    if (T[i].left != NIL) rec(T[i].left, d + 1);
}

void print(int i) {
    printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, T[i].depth);

    if (T[i].parent == NIL) printf("root, [");
    else if (T[i].left == NIL) printf("leaf, [");
    else printf("internal node, [");

    for (int j = 0, c = T[i].left; c != NIL; j++, c = T[c].right) {
        if (j) printf(", ");
        printf("%d", c);
    }

    printf("]\n");
}


int main(void) {
    int i, j, v, d, c, l, rt;
    scanf("%d", &n);
    for (i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;

    for (i = 0; i < n; i++) {
        cin >> v >> d;
        for (j = 0; j < d; j++) {
            cin >> c;
            if (j == 0) T[v].left = c;
            else T[l].right = c;
            l = c;
            T[c].parent = v;
        }
    }

    for (i = 0; i < n; i++) {
        if (T[i].parent == NIL) rt = i;
    }

    rec(rt, 0);

    for (i = 0; i < n; i++) print(i);

    return 0;
}