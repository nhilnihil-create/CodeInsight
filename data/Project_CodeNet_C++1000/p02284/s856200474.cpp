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

void _delete0(int s) {
    if (tree[tree[s].parent].left == s) {
        tree[tree[s].parent].left = NIL;
    }
    else {
        tree[tree[s].parent].right = NIL;
    }
}

void _delete1(int s) {
    int s2;
    if (tree[s].left != NIL) {
        s2 = tree[s].left;
    }
    else {
        s2 = tree[s].right;
    }

    if (tree[tree[s].parent].left == s) {
        tree[tree[s].parent].left = s2;
    }
    else {
        tree[tree[s].parent].right = s2;
    }
}

int next(int s) {
    if (s != NIL) {
        if (tree[s].left != NIL) {
            next(tree[s].left);
        }
        return s;
    }
}

void _delete(int v) {
    int s = find(root, v);
    cout << s << endl;
    if (s == NIL) {
        return;
    }

    int children = 0;
    if (tree[s].left != NIL) {
        children++;
    }
    if (tree[s].right != NIL) {
        children++;
    }

    if (s == root) {
        root = NIL;
        return;
    }

    if (children == 0) {

    }
    else if (children == 1) {

    }
}

void _delete2(int s) {
    int v = tree[next(s)].key;
    _delete(v);
    tree[s].key = v;
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