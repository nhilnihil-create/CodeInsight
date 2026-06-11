#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

const int NIL = -1;

struct Node {
    int id, parent, lchild, rsibling, depth;
    Node(): id(NIL), parent(NIL), lchild(NIL), rsibling(NIL) {}
};

struct Tree {
    vector<Node> nodes;
    int id_root;
    Tree(int n): nodes(vector<Node>(n)), id_root(NIL) {}

    Node& at(int i) {
        return nodes[i];
    }
    void get_root() {
        id_root = 0;
        while(nodes[id_root].parent != NIL) id_root = nodes[id_root].parent;
        nodes[id_root].depth = 0;
    }
    void set_depth_(int i) {
        if(nodes[i].lchild != NIL) {
            nodes[nodes[i].lchild].depth = nodes[i].depth + 1;
            set_depth_(nodes[i].lchild);
        }
        if(nodes[i].rsibling != NIL) {
            nodes[nodes[i].rsibling].depth = nodes[i].depth;
            set_depth_(nodes[i].rsibling);
        }
    }
    void set_depth() {
        get_root();
        set_depth_(id_root);
    }
    void print() {
        for(Node node: nodes) {
            printf("node %d: parent = %d, depth = %d, ", node.id, node.parent, node.depth);
            if(node.parent == NIL) printf("root");
            else if(node.lchild == NIL) printf("leaf");
            else printf("internal node");
            printf(", [");
            int id_child = node.lchild;
            while(id_child != NIL) {
                printf("%d", id_child);
                id_child = nodes[id_child].rsibling;
                if(id_child != NIL) printf(", ");
            }
            printf("]\n");
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, id, k, c, c_bfr;
    cin >> n;
    Tree tree(n);
    rep(i, n) {
        cin >> id >> k;
        tree.at(id).id = id;
        rep(j, k) {
            cin >> c;
            if(j == 0) tree.at(id).lchild = c;
            else tree.at(c_bfr).rsibling = c;
            tree.at(c).parent = id;
            c_bfr = c;
        }
    }

    tree.set_depth();
    tree.print();

    return 0;
}
