//Name: ALDS1_7_A: Rooted Trees
//Level: 2
//Category: Tree
//Note: left-child, right-sibling representation

#include <iostream>
#define MAX 100001
#define NIL -1

using namespace std;

struct Node { int par, left, right; };

Node T[MAX];
int n, depth[MAX];

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].par << ", ";
    cout << "depth = " << depth[u] << ", ";

    if (T[u].par == NIL) {
        cout << "root, ";
    }
    else if (T[u].left == NIL) {
        cout << "leaf, ";
    }
    else { cout << "internal node, "; }

    cout << "[";
    for (int i = 0, c = T[u].left; c != NIL; i++, c = T[c].right ) {
        if (i) { cout << ", "; }
        cout << c;
    }
    cout << "]" << endl;
}

void set_depth(int u, int p) {
    depth[u] = p;
    if (T[u].right != NIL) {
        set_depth(T[u].right, p);
    }
    if (T[u].left != NIL) {
        set_depth(T[u].left, p + 1);
    }
}

int main() {
    int d, v, c, l, r;

    cin >> n;

    for (int i = 0; i < n; i++) {
        T[i].par = T[i].left = T[i].right = NIL;
    }

    for (int i = 0; i < n; i++) {
        cin >> v >> d;
        for (int j = 0; j < d; j++) {
            cin >> c;
            if (j == 0) { T[v].left = c; }
            else { T[l].right = c; }
            l = c;
            T[c].par = v;
        }
    }

    for (int i = 0; i < n; i++) {
        if (T[i].par == NIL) {
            r = i;
        }
    }

    set_depth(r, 0);

    for (int i = 0; i < n; i++) { print(i); }

    return 0;
}
