#include <bits/stdc++.h>

using namespace std;

#define Vi vector<int>
#define FOR(i,s,e) for (int i=s; i<e; i++)
#define ITER(v) v.begin(), v.end()

constexpr int MAX_N = 1e5;

struct Node {
    int parent;
    int left;
    int right;
    int depth;
    Node(int parent=-1, int left=-1, int right=-1) :
        parent(parent), left(left), right(right) {}
};

Node tree[MAX_N];
int state[MAX_N]; // 0: not exists, 1: created, 2: mentioned

void add_node_to_tree(int id, int k, int c[]) {
    if (k > 0) {
        tree[id].left = c[0];
    }
    ++state[id];
    FOR(i,0,k) {
        int right = i==k-1 ? -1 : c[i+1];
        tree[c[i]].parent = id;
        tree[c[i]].right = right;
        ++state[c[i]];
    }
}

void set_depth(int n, int d) {
    tree[n].depth = d;
    if (tree[n].right != -1) {
        set_depth(tree[n].right, d);
    }
    if (tree[n].left != -1) {
        set_depth(tree[n].left, d+1);
    }
}

void print_tree(int n) {
    FOR(i,0,n) {
        cout << "node " << i << ": parent = " << tree[i].parent << ", depth = " << tree[i].depth << ", ";
        if (tree[i].depth == 0) {
            cout << "root, ";
        } else if (tree[i].left == -1) {
            cout << "leaf, ";
        } else {
            cout << "internal node, ";
        }
        int right = tree[i].left;
        cout << "[";
        while (true) {
            if (right == -1) { break; }
            cout << right;
            right = tree[right].right;
            if (right == -1) { break; }
            cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int id;
    int k;
    int c[MAX_N];
    FOR(i,0,n) {
        cin >> id >> k;
        FOR(j,0,k) {
            cin >> c[j];
        }
        add_node_to_tree(id, k, c);
    }
    int root = distance(state, find(state, state+n, 1));
    set_depth(root, 0);
    print_tree(n);

    return 0;
}