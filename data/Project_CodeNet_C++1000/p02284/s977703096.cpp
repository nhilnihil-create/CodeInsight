//     p           p
//     |           |
//     z     =>   NULL
//    / \
//   

//     p            p
//     |           /
//     z     =>   l
//    / 
//   l   

//     p            p
//     |           / \
//     z     =>   l   r
//    / \
//   l   r

// If z has no children, we modify its parent z.p to replace z with NIL as its child (delete z).
// If z has only a single child, we "splice out" z by making a new link between its child and its parent.
// If z has two children, we splice out z's successor y and replace z's key with y's key.


// Sample Input 1
// 18
// insert 8
// insert 2
// insert 3
// insert 7
// insert 22
// insert 1
// find 1
// find 2
// find 3
// find 4
// find 5
// find 6
// find 7
// find 8
// print
// delete 3
// delete 7
// print

// Sample Output 1
// yes
// yes
// yes
// no
// no
// no
// yes
// yes
//  1 2 3 7 8 22
//  8 2 1 3 7 22
//  1 2 8 22
//  8 2 1 22

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
using namespace std;

typedef struct NODE {
    int key;
    struct NODE *right;
    struct NODE *left;
    struct NODE *parent;
} Node;

int m;
Node *root;

Node *newNode(int key) {
    Node *n = new Node;
    n->key = key;
    n->right = NULL;
    n->left = NULL;
    n->parent = NULL;
    return n;
}

void insert(int key) {
    Node *r = root;
    Node *n;

    while (r) {
        if (key < r->key) {
            if (r->left) {
                r = r->left;
            } else {
                n = newNode(key);
                r->left = n;
                n->parent = r;
                return;
            }
        } else {
            if (r->right) {
                r = r->right;
            } else {
                n = newNode(key);
                r->right = n;
                n->parent = r;
                return;
            }
        }
    }
}

Node *search(int key) {
    Node *r = root;

    while (r) {
        if (r->key == key) {
            return r;
        }
        if (key < r->key) {
            r = r->left;
        } else {
            r = r->right;
        }
    }
    return r;
}

void find(int key) {
    if (search(key)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

// deleteはC++の予約語でした。。
void deleteN(int key) {
    Node *n = search(key);   
}

void walkInOrder(Node *n) {
    if (n != NULL) {
        if (n->left != NULL) {
            walkInOrder(n->left);
        }
        cout << " " << n->key;
        if (n->right != NULL) {
            walkInOrder(n->right);
        }
    }
}

void printInOrder() {
    walkInOrder(root);
    cout << endl;
}

void walkPreOrder(Node *n) {
    if (n != NULL) {
        cout << " " << n->key;
        if (n->left != NULL) {
            walkPreOrder(n->left);
        }
        if (n->right != NULL) {
            walkPreOrder(n->right);
        }
    }
}

void printPreOrder() {
    walkPreOrder(root);
    cout << endl;
}

void printBinarySearchTree() {
    printInOrder();
    printPreOrder();
}

void makeRoot(string inst, int key) {
    if (inst != "insert") {
        cout << "error" << endl;
        return;
    }
    root = newNode(key);
}

void readInst() {
    int key;
    string inst;
    cin >> inst >> key;
    makeRoot(inst, key);

    for (int i = 1; i < m; i++) {
        cin >> inst;
        if (inst == "insert") {
            cin >> key;
            insert(key);
        } else if (inst == "print") {
            printBinarySearchTree();
        } else if (inst == "find") {
            cin >> key;
            find(key);
        } else if (inst == "delete") {
            cin >> key;
            deleteN(key);
        } else {
            cout << "invalid instruction" << endl;
            return;
        }
    }
}

int main() {
    cin >> m;
    readInst();

    return 0;
}
