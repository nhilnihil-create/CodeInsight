#include <iostream>
using namespace std;
static const int MAX = 100005;
static const int NIL = -1;

struct Node {
    int p, l, r;
};

Node T[MAX];
int D[MAX], n;

void print(int u)
{
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "depth = " << D[u] << ", ";
    
    if (T[u].p == NIL) cout << "root";
    else if (T[u].l == NIL) cout << "leaf";
    else cout << "internal node";
    cout << ", [";

    for (int i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
        if (i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

void rec(int u, int p)
{
    D[u] = p;
    if (T[u].r != NIL) rec(T[u].r, p);
    if (T[u].l != NIL) rec(T[u].l, p + 1);
}

int main(int argc, char const *argv[])
{
    int i, j, v, d, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        T[i].p = T[i].l = T[i].r = NIL;
    }    
    int l;
    for (int i = 0; i < n; i++) {
        cin >> v >> d;
        for (int i = 0; i < d; i++) {
            cin >> c;
            if (i == 0) T[v].l = c;
            else T[l].r = c;
            l = c;
            T[c].p = v;
        }
    }
    int r;
    for (int i = 0; i < n; i++) {
        if (T[i].p == NIL) r = i;
    }

    rec(r, 0);

    for (int i = 0; i < n; i++) {
        print(i);
    }
    return 0;
}

