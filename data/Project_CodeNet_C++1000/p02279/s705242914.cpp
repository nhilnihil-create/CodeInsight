#include <iostream>

using namespace std;

const int MAX = 100'000;
const int NIL = -1;

struct Node {
    int parent = NIL;
    int left = NIL;
    int right = NIL;
};

Node T[MAX];
int D[MAX];

void setDepth(int u, int d) {
    D[u] = d;
    if (T[u].left != NIL) setDepth(T[u].left, d + 1);
    if (T[u].right != NIL) setDepth(T[u].right, d);
}

void print(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";
    if (T[u].parent == NIL) {
        cout << "root, ";
    } else if (T[u].left == NIL) {
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }
    cout << "[";
    int c = T[u].left, i = 0;
    while (c != NIL) {
        if (i) {
            cout << ", ";
        }
        cout << c;
        c = T[c].right;
        i++;
    }
    cout << "]" << endl;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id, k;
        cin >> id >> k;
        if (k) {
            int c;
            cin >> c;
            T[id].left = c;
            T[c].parent = id;
            for (int j = 0; j < k - 1; j++) {
                cin >> T[c].right;
                T[T[c].right].parent = id;
                c = T[c].right;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (T[i].parent == NIL) {
            setDepth(i, 0);
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        print(i);
    }
}
