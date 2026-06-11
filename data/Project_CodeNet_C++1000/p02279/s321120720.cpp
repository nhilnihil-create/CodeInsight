#include <iostream>
#include <vector>

using namespace std;

#define NIL -1

struct Node {
    int parent;
    int left;
    int right;
    int depth;

    bool operator<(const Node &right) const {
        return parent < right.parent;
    }
};

const int MAX_N = 100000;
Node T[MAX_N];


int get_depth(int location) {
    int depth = 0;
    while (T[location].parent != -1) {
        depth++;
        location = T[location].parent;
    }
    return depth;
}

void printChildren(int location) {
    vector<int> children;
    if (T[location].left != -1) {
        location = T[location].left;
        children.push_back(location);
        while (T[location].right != -1) {
            location = T[location].right;
            children.push_back(location);
        }
    }

    for (int i = 0; i < children.size(); ++i) {
        if (i)
            cout << ", ";
        cout << children[i];
    }
}

void print(int location) {
    cout << "node " << location << ": ";
    cout << "parent = " << T[location].parent << ", ";
    cout << "depth = " << get_depth(location) << ", ";
    if (T[location].parent == -1) {
        cout << "root, ";
        cout << "[";
        printChildren(location);
        cout << "]" << endl;
    } else if (T[location].left != -1) {
        cout << "internal node, ";
        cout << "[";
        printChildren(location);
        cout << "]" << endl;
    } else {
        cout << "leaf, ";
        cout << "[]" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        T[i].parent = -1;
        T[i].left = -1;
        T[i].right = -1;
        T[i].depth = -1;
    }

    for (int i = 0; i < n; ++i) {
        int children;
        int position;
        cin >> position;
        cin >> children;
        for (int j = 0; j < children; ++j) {
            int child_node;
            int log;
            cin >> child_node;

            T[child_node].parent = position;
            if (!j) {
                T[position].left = child_node;
                log = child_node;
            } else {
                T[log].right = child_node;
                log = child_node;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        print(i);
    }
}