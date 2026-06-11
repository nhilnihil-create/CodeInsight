#include <bits/stdc++.h>
using namespace std;

struct Node {
    int index = -1;
    int depth = -1;
    int parent = -1;
    int *child;
    int ccnt = 0;
};

int get_depth(Node *node, int index) {
    if (node[index].parent < 0) {
        return 0;
    } else if (node[index].depth > 0){
        return node[index].depth;
    } else {
        int p = node[index].parent;
        int d = get_depth(node, p) + 1;
        for (int i = 0; i < node[p].ccnt; ++i) { node[node[p].child[i]].depth = d;}
        return node[index].depth;
    }
}

int main() {
    int n;
    cin >> n;
    Node a[n];
    
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].index = x;
        a[x].child = new int[y];
        a[x].ccnt = y;
        for (int j = 0; j < a[x].ccnt; ++j) {
            int b;
            cin >> b;
            a[x].child[j] = b;
            a[b].parent = x;
        }
    }
    
    for (auto& i : a) {
        cout << "node " << i.index << ": ";
        cout << "parent = " << i.parent << ", ";
        cout << "depth = " << get_depth(a, i.index) << ", ";
        cout << (i.parent < 0 ? "root" : (i.ccnt < 1 ? "leaf" : "internal node")) << ", ";
        cout << "[";
        for (int j = 0; j < i.ccnt-1; ++j) {
            cout << i.child[j] << ", ";
        }
        if (i.ccnt) { 
            cout << i.child[i.ccnt-1] << "]" << endl;
        } else {
            cout << "]" << endl;
        }
    }
    
    return 0;
}