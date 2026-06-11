#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
#define NIL -2000000001
 
struct Node {
    int key;
    int parent = NIL;
    int left = NIL;
    int right = NIL;
};
 
 int root = NIL;
Node tree[500000];
 
void preorder(int s) {
    if (s != NIL) {
        cout << " " << tree[s].key;
        if (tree[s].left != NIL) {
            preorder(tree[s].left);
        }
        if (tree[s].right != NIL) {
            preorder(tree[s].right);
        }
    }
}
 
void inorder(int s) {
    if (s != NIL) {
        if (tree[s].left != NIL) {
            inorder(tree[s].left);
        }
        cout << " " << tree[s].key;
        if (tree[s].right != NIL) {
            inorder(tree[s].right);
        }
    }
}
 
void insert(int s) {
    int y = NIL;
    int x = root;
 
    while (x != NIL) {
        y = x;
        if (tree[s].key < tree[x].key) {
            x = tree[x].left;
        }
        else {
            x = tree[x].right;
        }
    }
    tree[s].parent = y;

    if (root == NIL) {
        root = s;
        return;
    }
 
    if (tree[s].key < tree[y].key) {
        tree[y].left = s;
    }
    else {
        tree[y].right = s;
    }
}
 
int find(int s, int v) {
    if (v == tree[s].key) {
        return s;
    }
    else if (v < tree[s].key) {
        if (tree[s].left == NIL) {
            return NIL;
        }
        find(tree[s].left, v);
    }
    else {
        if (tree[s].right == NIL) {
            return NIL;
        }
        find(tree[s].right, v);
    }
}

void _delete(int v) {
    int s = find(0, v);
    if (s == 0) {
        return;
    }

    if (tree[s].left == NIL && tree[s].right == NIL) {

    }
}
 
int main() {
    int n, value;
    string str;
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "insert") {
            cin >> value;
            tree[i].key = value;
            insert(i);
        }
        else if (str == "print") {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
        else if (str == "find") {
            cin >> value;
            if (find(root, value) != NIL) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else if (str == "delete") {
            cin >> value;
            _delete(value);
        }
    }
 
    return 0;
}