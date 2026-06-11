#include <iostream>
using namespace std;
int N;

struct Node {
    int p, l, r;
};
Node *nd;


void preorder(int k) {
    cout << " " << k;
    if (nd[k].l != -1) {
        preorder(nd[k].l) ;
    }
    if (nd[k].r != -1) {
        preorder(nd[k].r);
    }
}

void inorder(int k) {
    if (nd[k].l != -1) {
        inorder(nd[k].l) ;
    }
    cout << " " << k;
    if (nd[k].r != -1) {
        inorder(nd[k].r);
    }
}

void postorder(int k) {
    if (nd[k].l != -1) {
        postorder(nd[k].l) ;
    }
    if (nd[k].r != -1) {
        postorder(nd[k].r);
    }
    cout << " " << k;
}
int main() {
    cin >> N;
    int id, l, r;
    nd = new Node[N];
    for (int j = 0; j < N; ++j) {
        nd[j].l = nd[j].r = nd[j].p = -1;
    }
    for (int i = 0; i < N; ++i) {
        cin >> id >> l >> r ;
        nd[id].l = l; nd[id].r = r;
        nd[l].p = id; nd[r].p = id;
    }

    int root ;
    while (nd[root].p != -1) {
        root = nd[root].p;
    }

    cout << "Preorder" << endl;
    preorder(root );
    cout << endl;
    cout << "Inorder" << endl;
    inorder(root);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(root);
    cout << endl;



    return 0;
}

