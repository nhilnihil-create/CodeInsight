#include <iostream>
using namespace std;
#define NIL -1
#define MAX 100001

// left-child, right-sibling representation
struct Node {
    int p, l, r;
};

Node T[MAX];
int D[MAX];

// Set depth for each node using recursion
void setDepth(int id, int d) {
    D[id] = d;
    if (T[id].l != NIL) setDepth(T[id].l, d+1);
    if (T[id].r != NIL) setDepth(T[id].r, d); 
}

void printTree(int n) {
    int i, j, c;

    for (i=0; i < n; i++) {
        cout << "node " << i << ": ";
        cout << "parent = " << T[i].p << ", ";
        cout << "depth = " << D[i] << ", ";

        if (T[i].p == NIL) cout << "root, ";
        else if (T[i].l == NIL) cout  << "leaf, ";
        else cout << "internal node, ";

        cout << "[";
        if (T[i].l != NIL) {
            c = T[i].l;
            for (j=0; c != NIL; j++) {
                if (j != 0) cout << ", ";
                cout << c;
                c = T[c].r;
            }
        }
        cout << "]" << endl;
    }
}

int main() {
    int n, id, k, c, pc, r, i, j;

    cin >> n;
    for (i=0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL;
    
    for (i=0; i < n; i++) {
        cin >> id >> k;
        for (j=0; j < k; j++) {
            cin >> c;
            if (j == 0) {
                T[id].l = c;
            } else {
                T[pc].r = c;
            }
            T[c].p = id;
            pc = c;
        }

    }
    for (i=0; i < n; i++) {
        if (T[i].p == NIL) r = i;
    }
    setDepth(r, 0);
    printTree(n);

    return 0;
}
