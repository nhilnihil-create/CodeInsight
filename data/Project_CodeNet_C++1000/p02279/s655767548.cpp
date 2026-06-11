#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {int parent, left, right; };

Node T[MAX];
int N, D[MAX];

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";

    if (T[u].parent == NIL)
        cout << "root, ";
    else if (T[u].left == NIL)
        cout << "leaf, ";
    else
        cout << "internal node, ";

    cout << "[";
    for (int i = 0, c = T[u].left; c != NIL; i++, c = T[c].right) {
        if (i > 0) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

void set_depth(int u, int p) {
    D[u] = p;
    if (T[u].right != NIL)
        set_depth(T[u].right, p);
    if (T[u].left != NIL)
        set_depth(T[u].left, p + 1);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        T[i].parent = T[i].left = T[i].right = NIL;

    int left = 0;
    for (int i = 0; i < N; i++) {
        int v, k;
        cin >> v >> k;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            if (j == 0) T[v].left = c;
            else T[left].right = c;
            left = c;
            T[c].parent = v;
        }
    }

    int root = 0;
    for (int i = 0; i < N; i++) {
        if (T[i].parent == NIL) root = i;
    }

    set_depth(root, 0);

    for (int i = 0; i < N; i++)
        print(i);

    return 0;
}
