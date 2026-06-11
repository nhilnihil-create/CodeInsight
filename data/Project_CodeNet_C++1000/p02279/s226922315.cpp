#include <iostream>
#include <vector>
#include <set>
using namespace std;


struct node{
    int id;
    int k;
    int depth;
    int parent;
    vector<int> child;
};
int main()
{
    int n, id, k;
    cin >> n;
    vector<node> tree;
    tree.resize(n);
    for (int i = 0; i < n; i++)
    {
        tree[i].parent = -1;
        tree[i].depth = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> id >> k;
        tree[id].id = id;
        tree[id].k = k;
        if (k != 0)
        {
            tree[id].child.resize(k);
            for (int j = 0; j < k; j++)
            {
                cin >> tree[id].child[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (tree[i].k != 0)
        {
            for(int j = 0; j < tree[i].k; j++)
            {
                tree[tree[i].child[j]].parent = tree[i].id;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (tree[j].parent != -1)
        {
            j = tree[j].parent;
            tree[i].depth++;
        }

    }
    for (int i = 0; i < n; i++)
    {
        cout<< "node " << tree[i].id << ": " << "parent = " << tree[i].parent << ", " << "depth = " << tree[i].depth << ", ";
        if (tree[i].k == 0 && tree[i].depth != 0)
        {
            cout << "leaf, []" << endl;
        }

        else
        {
            if (tree[i].depth == 0)
                cout << "root, [";
            else cout<< "internal node, [";
            for (int j = 0; j < tree[i].k; j++)
            {
                cout << tree[i].child[j] ;
                if (j != tree[i].k-1) cout << ", ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}