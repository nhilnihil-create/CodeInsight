#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *null, *root;

void insert(int key) {
    Node *tmp, *pre, *next;

    next = new Node;
    next->key = key;
    next->left = null;
    next->right = null;
    pre = null;
    tmp = root;

    while (tmp != null) {
        pre = tmp;
        if (next->key < tmp->key)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }

    next->parent = pre;
    if (pre == null)
        root = next;
    else if (next->key < pre->key)
        pre->left = next;
    else
        pre->right = next;
}

void preorder(Node *node) {
    if (node == null)
        return;
    cout << " " << node->key;

    if (node->left != null)
        preorder(node->left);
    if (node->right != null)
        preorder(node->right);
}
void inorder(Node *node) {
    if (node == null)
        return;

    if (node->left != null)
        inorder(node->left);
    cout << " " << node->key;
    if (node->right != null)
        inorder(node->right);
}

int main() {

    int n;
    cin >> n;

    rep(i, n) {
        string s;
        cin >> s;

        if (s == "insert") {
            int a;
            cin >> a;
            insert(a);
        } else {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }

    return 0;
}
