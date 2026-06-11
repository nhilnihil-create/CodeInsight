#include <cstdio>
#define NIL -1

struct Node {
    int parent, left, right;
};

int *D;
Node *T;

void print(int u) {
    printf("node %d: parent = %d, depth = %d, ", u, T[u].parent, D[u]);

    if (T[u].parent == NIL) { printf("root, "); }
    else if (T[u].left != NIL) { printf("internal node, "); }
    else { printf("leaf, "); }

    printf("[");
    for (int i = 0, c = T[u].left; c != NIL; i++, c = T[c].right) {
        if (i) { printf(", "); }
        printf("%d", c);
    }
    printf("]\n");
}

void setDepth(int u, int p) {
    D[u] = p;
    if (T[u].right != NIL) {
        setDepth(T[u].right, p);
    }
    if (T[u].left != NIL) {
        setDepth(T[u].left, p+1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    D = new int[n];
    T = new Node[n];

    for (int i = 0; i < n; i++) {
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    for (int i = 0; i < n; i++) {
        int v, k;
        scanf("%d %d", &v, &k);
        for (int j = 0; j < k; j++) {
            int c, left;
            scanf("%d", &c);
            if (j == 0) { 
                T[v].left = c;
            } else {
                T[left].right = c;
            }
            left = c;
            T[c].parent = v;
        }
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (T[i].parent == NIL) {
            root = i;
            break;
        }
    }

    setDepth(root, 0);

    for (int i = 0; i < n; i++) {
        print(i);
    }

    return 0;
}
