#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *p, *l, *r;
};

Node *root, *NIL;

void insert(int k) {
    Node *tmp_p = NIL;
    Node *tmp = root;
    Node *z = new Node;

    // z = (Node *)malloc(sizeof(Node));
    z = new Node;
    z->key = k;
    z->l = NIL;
    z->r = NIL;

    while (tmp != NIL) {
        tmp_p = tmp;
        if (z->key < tmp->key) {
            tmp = tmp->l;
        }
        else {
            tmp = tmp->r;
        }
    }

    z->p = tmp_p;
    if (tmp_p == NIL) {
        root = z;
    }
    else {
        if (z->key < tmp_p->key) {
            tmp_p->l = z;
        }
        else {
            tmp_p->r = z;
        }
    }
}

Node * find(int k, Node *u) {
    while (u != NIL && k != u->key)
    {
        if (k < u->key)
        {
            u = u->l;
        }
        else
        {
            u = u->r;
        }
    }
    return u;
}

void inorder(Node *u) {
    if (u == NIL) {
        return;
    }

    inorder(u->l);
    cout << " " << u->key;
    inorder(u->r);
}

void preorder(Node *u) {
    if (u == NIL) {
        return;
    }

    cout << " " << u->key;
    preorder(u->l);
    preorder(u->r);
}

int main() {
    int N;
    cin >> N;

    string command;
    int node_i;

    for (int i = 0; i < N; i++)
    {
        cin >> command;
        if (command == "insert") {
            cin >> node_i;
            insert(node_i);
        }
        else if (command == "find") {
            cin >> node_i;
            Node *tmp = find(node_i, root);
            if (tmp != NIL)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        else if (command == "print")
        {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
}
