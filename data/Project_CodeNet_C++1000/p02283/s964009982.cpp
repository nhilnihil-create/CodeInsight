#include <stdio.h>

#define NMAX 500000
#define NIL -1
int n;
int root = NIL;
int id = 0;       // new node id (=node count in the tree)
int P[NMAX + 10]; // parent
int L[NMAX + 10]; // left child
int R[NMAX + 10]; // right child
int V[NMAX + 10]; // value

void insert(int val) {
    V[id] = val;
    L[id] = NIL;
    R[id] = NIL;
    // all below is to set P[id], L[P[id]], R[P[id]]

    if (root == NIL) {
        P[id] = NIL;
        root = id;
        id++;
        return;
    }
    int c = root;
    int parent = NIL; // parent = P[id]
    // find P[id]
    while (c != NIL) {
        parent = c;
        if (val <= V[c])
            c = L[c];
        else
            c = R[c];
    }
    P[id] = parent;
    // update L[parent] or R[parent]
    if (V[id] <= V[parent])
        L[parent] = id;
    else
        R[parent] = id;
    id++;
}

void pre_order(int _root) {
    if (_root == NIL)
        return;
    printf(" %d", V[_root]);
    pre_order(L[_root]);
    pre_order(R[_root]);
}

void in_order(int _root) {
    if (_root == NIL)
        return;
    in_order(L[_root]);
    printf(" %d", V[_root]);
    in_order(R[_root]);
}

int main() {
    scanf("%d", &n);
    char cmd[10];
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%s", cmd);
        if (cmd[0] == 'i') {
            scanf("%d", &val);
            insert(val);
        } else {
            in_order(root);
            printf("\n");
            pre_order(root);
            printf("\n");
        }
    }
    return 0;
}
