#include <iostream>
using namespace std;

#define NIL -1

struct Node { int parent, right, left; };
int D[100000];
Node T[100000];

void rec(int u, int d) {
    D[u] = d;
    if (T[u].right != NIL) { rec(T[u].right, d); }
    if (T[u].left != NIL) { rec(T[u].left, d + 1); }
}

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] <<", ";

    if (T[u].parent == NIL) { cout << "root, "; }
    else if (T[u].left != NIL) { cout << "internal node, "; }
    else { cout << "leaf, "; }

    cout << "[";
    int i = u;
    if (T[i].left != NIL) {
        cout << T[i].left; i = T[i].left;
        if (T[i].right != NIL) { cout << ", ";}
        while (T[i].right != NIL) {
            cout << T[i].right;
            i = T[i].right;
            if (T[i].right != NIL) { cout << ", "; }
        }
    }
    cout << "]" << endl;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        T[i].parent = T[i].right = T[i].left = NIL;
        D[i] = NIL;
    }
    for (int i = 0; i < n; ++i) {
        int id ,k, d; cin >> id >> k; d = id;
        for (int j = 0; j < k; ++j) {
            int c; cin >> c;
            if (j == 0) { T[id].left = c; }
            else { T[d].right = c; }
            d = c;
            T[c].parent = id;
        }
    }
    int u = 0;
    for (int i = 0; i < n; ++i) {
        if (T[i].parent == NIL) u = i;
    }
    rec(u, 0);
    for (int i = 0; i < n; ++i) {
        print(i);
    }
}