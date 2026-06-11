#include <bits/stdc++.h>
using namespace std;

struct Node {
    int index = -1;
    int depth = -1;
    int parent = -1;
    int *child;
    int ccnt = 0;
    int type = 0;
};

void depth(Node *node, int x, int d) {
    node[x].depth = d;
    for (int i = 0; i < node[x].ccnt; ++i) {
        depth(node, node[x].child[i], d+1);
    }
}

int Root(Node *node, int x) {
    if (node[x].parent > -1) {
        Root(node, node[x].parent);
    } else {
        return x;
    }
}

int main() {
    int n, b, x, y, root;
    string child;
    string type[] = {"leaf", "internal node", "root"};
    cin >> n;
    Node a[n];
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        a[x].index = x;
        a[x].child = new int[y];
        a[x].ccnt = y;
        for (int j = 0; j < y; ++j) {
            cin >> b;
            a[x].child[j] = b;
            a[x].type = 1;
            a[b].parent = x;
        }
    }
    
    root = Root(a, 0);
    a[root].type = 2;
    depth(a, root, 0);
    
    for (auto& i : a) {
        cout << "node " << i.index << ": parent = " << i.parent << ", depth = " << i.depth << ", " << type[i.type] << ", ";
        child = "[";
        for (int j = 0; j < i.ccnt-1; ++j) {
            child += to_string(i.child[j]) + ", ";
        }
        if (i.ccnt) { 
            child += to_string(i.child[i.ccnt-1]) + "]\n";
        } else {
            child += "]\n";
        }
        cout << child;
    }
    
    return 0;
}