#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int kSize = 100000;

struct Node {
    int parent = -1;
    int depth;
    vector<int> children;
};

Node tree[kSize];

void GetDepth(int node) {
    int ans = 0;
    int var = node;
    while (tree[var].parent != -1) {
        var = tree[var].parent;
        ans++;
    }

    tree[node].depth = ans;
}

void Print(int node) {
    printf("node %d: parent = %d, depth = %d, ", node, tree[node].parent, tree[node].depth);
    if (tree[node].parent == -1) {
        cout << "root, ";
    } else if (tree[node].children.empty()) {
        cout << "leaf, ";
    } else {
        cout << "internal node, ";
    }

    if (tree[node].children.empty()) {
        cout << "[]";
    } else {
        cout << "[";
        vector<int> v = tree[node].children;
        for (int i = 0; i < v.size(); ++i) {
            if (i != v.size() - 1) {
                cout << v[i] << ", ";
            } else {
                cout << v[i];
            }
        }
        cout << "]";
    }

    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id, k;
        cin >> id >> k;
        for (int i = 0; i < k; ++i) {
            int c;
            cin >> c;
            tree[c].parent = id;
            tree[id].children.push_back(c);
        }
    }

    for (int i = 0; i < n; ++i) {
        GetDepth(i);
    }

    for (int i = 0; i < n; ++i) {
        Print(i);
    }
    return 0;
}

