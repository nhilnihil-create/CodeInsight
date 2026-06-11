#include <iostream>

using namespace std;

const int NIL = -1;

struct Node{
    int id, parent, bro, num_childs, child, depth;
};

void setDepth(Node* tree, int id, int d)
{
    tree[id].depth = d;
    if(tree[id].child != NIL) setDepth(tree, tree[id].child, d+1);
    if(tree[id].bro != NIL) setDepth(tree, tree[id].bro, d);
}

int main()
{
    int n, id, c, k, bro;
    Node tree[200000];
    cin >> n;
    for(int i=0;i<n;++i)
    {
        tree[i].parent = tree[i].child = tree[i].bro = NIL;
        tree[i].depth = 0;
    }
    for(int i=0;i<n;++i)
    {
        cin >> id >> k;
        tree[id].num_childs = k;
        tree[id].id = id;
        for(int j=0;j<k;++j)
        {
            cin >> c;
            tree[c].parent = id;
            if(j){
                tree[bro].bro = c;
            }
            else{
                tree[id].child = c;
            }
            bro = c;
        }
    }

    int root = 0;
    for(int i=0;i<n;++i){
        if(tree[i].parent == NIL) 
        {
            root = i;
            break;
        }
    }
    setDepth(tree, root, 0);

    for(int i=0;i<n;++i)
    {
        cout << "node " << i << ": parent = " << tree[i].parent << ", depth = " << tree[i].depth << ", ";
        if(tree[i].parent == -1) cout << "root, ";
        else if(tree[i].num_childs == 0) cout << "leaf, ";
        else cout << "internal node, ";
        cout << "[";
        c = tree[i].child;
        for(int j=0;j<tree[i].num_childs;++j)
        {
            if(j) cout << ", ";
            cout << tree[c].id;
            c = tree[c].bro;
        }
        cout << "]" << endl;
    }
}

