#include <iostream>
using namespace std;

struct Node {
    Node *parent;
    Node *left;
    Node *right;
    int key;
};

Node *NIL, *root;

void init() {
    root = NIL;
}

void insert(int key) {
    Node *y = NIL;
    Node *x = root;
    while (x != NIL) {
        y = x;
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->parent = y;
    node->key = key;
    node->left = NIL;
    node->right = NIL;
    if (y == NIL) {
        root = node;
    } else if (key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }
}

Node* find(int key) {
    Node *x = root;
    while (x != NIL && x->key != key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    return x;
}

void deleteNode(int key) {

}

void printByPreorder(Node *node) {
    if (node == NIL) {
        return;
    }

    cout << " "<< node->key;
    printByPreorder(node->left);
    printByPreorder(node->right);
}

void printByInorder(Node *node) {
    if (node == NIL) {
        return;
    }

    printByInorder(node->left);
    cout << " "<< node->key;
    printByInorder(node->right);
}

int main() {
    int n;
    cin >> n;

    string command;
    int key;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "insert") {
            cin >> key;
            insert(key);
        } else if (command == "find") {
            cin >> key;
            Node *node = find(key);
            if (node != NIL) cout << "yes" << endl;
            else cout << "no" << endl;
        } else if (command == "delete") {
            cin >> key;
            deleteNode(key);
        } else {
            printByInorder(root);
            cout << endl;
            printByPreorder(root);
            cout << endl;
        }
    }

    return 0;
}

