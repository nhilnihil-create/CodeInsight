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
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, root;
    string type[] = {"leaf, [", "internal node, [", "root, ["};
    cin >> n;
    Node a[n];
    for (int i = 0; i < n; ++i) {
        cin >> x;
        cin >> a[x].ccnt;
        a[x].index = x;
        a[x].child = new int[a[x].ccnt];
        for (int j = 0; j < a[x].ccnt; ++j) {
            a[x].type = 1;
            cin >> a[x].child[j];
            a[a[x].child[j]].parent = x;
        }
    }
     
    root = Root(a, 0);
    a[root].type = 2;
    depth(a, root, 0);
     
    for (auto& i : a) {
        cout << "node " << i.index << ": ";
        cout << "parent = " << i.parent << ", ";
        cout << "depth = " << i.depth << ", ";
        cout << type[i.type];
        for (int j = 0; j < i.ccnt-1; ++j) {
            cout << i.child[j] << ", ";
        }
        if (i.ccnt) { 
            cout << i.child[i.ccnt-1] << "]\n";
        } else {
            cout << "]\n";
        }
    }
     
    return 0;
}