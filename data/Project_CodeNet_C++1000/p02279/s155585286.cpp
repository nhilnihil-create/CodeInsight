#include <iostream>

using namespace std;

typedef struct node {
        int parent;
        int childs;
        int leftChild;
        int rightSib;

        node();
} node;

node::node()
        :parent(-1), childs(0), leftChild(-1), rightSib(-1)
        {
        }

void insert(node tree[], int id, int child[], int childs)
{
        tree[id].leftChild = child[0];
        for (int i = 0; i < childs; i++) {
                tree[child[i]].parent = id;
                if (i < childs - 1) {
                        tree[child[i]].rightSib = child[i + 1];
                }
        }
}

int main()
{
        int n;
        cin >> n;
        node *tree = new node[n];
        int id, k;
        for (int i = 0; i < n; i++) {
                cin >> id >> k;
                tree[id].childs = k;
                if (k) {
                        int *c = new int[k];
                        for (int j = 0; j < k; j++) {
                                cin >> c[j];
                        }
                        insert(tree, id, c, k);
                        delete [] c;
                }
        }
        for (int i = 0; i < n; i++) {
                cout << "node " << i << ": ";
                cout << "parent = " << tree[i].parent << ", ";
                cout << "depth = ";
                int depth = 0, parent = tree[i].parent;
                while (parent != -1) {
                        parent = tree[parent].parent;
                        depth++;
                }
                cout << depth << ", ";
                if (tree[i].parent == -1) {
                        cout << "root, ";
                }
                else if (tree[i].leftChild != -1) {
                        cout << "internal node, ";
                }
                else {
                        cout << "leaf, ";
                }
                cout << "[";
                int child = tree[i].leftChild;
                int j = 0;
                for (int child = tree[i].leftChild; child != -1; child = tree[child].rightSib) {
                        cout << child;
                        if (j < tree[i].childs - 1) {
                                cout << ", ";
                        }
                        j++;
                }
                cout << "]" << endl;
        }
        delete [] tree;

        return 0;
}