#include <iostream>
using namespace std;

#define MAXSIZE 100100

struct Node { int parent, left, right; };

Node T[MAXSIZE];
int n, Depth[MAXSIZE];

void setDepth(int u, int depth) {
    Depth[u] = depth;
    if (T[u].right != -1) setDepth(T[u].right, depth);
    if (T[u].left != -1) setDepth(T[u].left, depth + 1);
    return;
}

void print(int u) {
    cout << "node " << u << ": parent = " << T[u].parent;
    cout << ", depth = " << Depth[u] << ", ";
    if (T[u].parent == -1) cout << "root, ";

    else if (T[u].left == -1) cout << "leaf, ";
    else cout << "internal node, ";
    
    cout << "[";
    int i = 0, child = T[u].left;
    while (child != -1) {
        if (i) cout << ", ";
        cout << child;
        child = T[child].right;
        i++;
    }
    cout << "]" << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        T[i].parent = T[i].left = T[i].right = -1;
    }

    int id, k, child, left_sibling;
    for (int i = 0; i < n; i++) {
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> child;
            if (j == 0) T[id].left = child;
            else T[left_sibling].right = child;
            left_sibling = child;
            T[child].parent = id;
        }
    }

    int parent;
    for (int i = 0; i < n; i++) {
        if (T[i].parent == -1) parent = i;
    }

    setDepth(parent, 0);

    for (int i = 0; i < n; i++) print(i);
    return 0;
}
