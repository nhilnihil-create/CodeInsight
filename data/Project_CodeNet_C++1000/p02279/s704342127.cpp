#include <bits/stdc++.h>
using namespace std;

struct Node {
    int index = -1;
    int depth = -1;
    int parent = -1;
    vector<int> child;
};

int get_depth(Node *node, int index) {
    if (node[index].parent < 0) {
        return 0;
    } else {
        return get_depth(node, node[index].parent) + 1;
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
        for (int j = 0; j < y; ++j) {
            int b;
            cin >> b;
            a[x].child.push_back(b);
            a[b].parent = x;
            if (a[x].depth > -1) { a[b].depth = a[x].depth + 1; }
        }
    }
    
    for (auto& i : a) {
        string child = "";
        for (auto& j : i.child) {
            string c = child == "" ? "" : ", ";
            child += c + to_string(j);
        }
        cout << "node " << i.index << ": ";
        cout << "parent = " << i.parent << ", ";
        cout << "depth = " << get_depth(a, i.index) << ", ";
        cout << (i.parent < 0 ? "root" : (i.child.size() < 1 ? "leaf" : "internal node")) << ", ";
        cout << "[" << child << "]" << endl;
    }
    
    return 0;
}