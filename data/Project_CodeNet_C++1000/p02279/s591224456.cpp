#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {
    int p, l, r;
};

void setDepth(int u, int p, Node tree[], int depth[]) {
    depth[u] = p;
    if (tree[u].r != NIL) setDepth(tree[u].r, p, tree, depth);
    if (tree[u].l != NIL) setDepth(tree[u].l, p + 1, tree, depth);
}

void printTree(int u, Node tree[], int depth[]) {
    cout << "node " << u << ": ";
    cout << "parent = " << tree[u].p << ", ";
    cout << "depth = " << depth[u] << ", ";

    if (tree[u].p == NIL) cout << "root, ";
    else if (tree[u].l == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";

    for (int i = 0, c = tree[u].l; c != NIL; i++, c = tree[c].r) {
        if (i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int main() {
    Node tree[MAX];
    int n, depth[MAX];
    cin >> n;
    for (int i = 0; i < n; i++) {
        tree[i].p = tree[i].l = tree[i].r = NIL;
    }

    int d, v, c, l, r;
    for (int i = 0; i < n; i++) {
        cin >> v >> d;
        for (int j = 0; j < d; j++) {
            cin >> c;
            if (j == 0) tree[v].l = c;
            else tree[l].r = c;
            l = c;
            tree[c].p = v;
        }
    }
    for (int i = 0; i < n; i++) {
        if (tree[i].p == NIL) {
            r = i;
            break;
        }
    }

    setDepth(r, 0, tree, depth);
    for (int i = 0; i < n; i++) {
        printTree(i, tree, depth);
    }
}

