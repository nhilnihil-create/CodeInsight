#include <iostream>

using namespace std;

int nil = -1;
int N;


struct Node {
    int id;
    int left, right, parent;
};

Node *nodes;

/*
 * 左子右兄弟表現
 */

int depth(int m) {
    int d = 0;
    while (true) {
        if (nodes[m].parent != nil) {
            d++;
            m = nodes[m].parent;
        } else break;
    }
    return d;
}

string type(int m) {
    if (nodes[m].parent == nil) {
        return  "root";
    } else if (nodes[m].left != nil) {
        return "internal node";
    } else {
        return "leaf";
    }

}

int main() {
    cin >> N;
    nodes = new Node [N];

    for (int k = 0; k < N; ++k) {
        nodes[k].left = nodes[k].right = nodes[k].parent = nil;
    }

    for (int i = 0; i < N; ++i) {
        int d;
        int nod ;
        cin >> nod >>  d;
        nodes[i].id = nod;
        int l;
        for (int j = 0; j < d; ++j) {
            int c;
            cin >> c;
            if (j == 0) nodes[nod].left = c;
            else nodes[l].right = c;

            l = c;
            nodes[c].parent = nod;
        }
    }

    for (int m = 0; m < N; ++m) {
        cout << "node " << m << ": parent = " << nodes[m].parent << ", depth = " << depth(m) << ", " << type(m);
        int i = nodes[m].left;
        if (nodes[m].left == nil) {
            cout << ", []" << endl;
            continue;
        }
        cout << ", [";
        while(true) {
            cout << i;
            if (nodes[i].right != nil) {
                cout << ", ";
                i = nodes[i].right;
            } else break;
        }
        cout << "]" << endl;
    }
    return 0;
}


