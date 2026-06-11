#include <iostream>
using namespace std;

#define N 100001
#define NIL -1

struct Node {
    int parent;
    int left;
    int right;
};

Node tree[N];

int computeDepth (Node node) {
    int depth = 0;
    int parent_number;
    while (node.parent != -1) {
        depth++;
        node = tree[node.parent];
    }

    return depth;
}

string returnType(Node node) {
    if (node.parent == -1) {
        return "root";
    } else if (node.left != -1) {
        return "internal node";
    } else {
        return "leaf";
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        tree[i].parent = NIL;
        tree[i].left = NIL;
        tree[i].right = NIL;
    }

    int number;
    int degree;
    for (int i = 0; i < n; i++) {
        cin >> number;
        cin >> degree;

        int child_number;
        int left;
        for (int j = 0; j < degree; j++) {
            cin >> child_number;
            if (j == 0) tree[number].left = child_number;
            else tree[left].right = child_number;
            left = child_number;
            tree[child_number].parent = number;
        }
    }

    for (int i = 0; i < n; i++) {
        Node node = tree[i];
        cout << "node" << " " << i << ": ";
        cout << "parent = " <<  node.parent << ", ";
        cout << "depth = " << computeDepth(node) << ", ";
        cout << returnType(node) << ", ";
        cout << "[";
        int child = node.left;
        int j = 0;
        while (child != -1) {
            if (j != 0) cout << ", ";
            cout << child;
            child = tree[child].right;
            j++;
        }
        cout << "]";
        cout << endl;
    }
}
