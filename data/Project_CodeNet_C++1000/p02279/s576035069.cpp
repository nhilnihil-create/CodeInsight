#include <bits/stdc++.h>

#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)

using namespace std;


// data
struct Node
{
    Node()
    {
        parent = -1;
        depth = 0;
    }
    int parent;
    vector<int> children;
    int depth;
};
vector<Node> tree;

void calDepth(int id){
    int iid = id;
    while (tree[iid].parent != -1)
    {
        tree[id].depth++;

        iid = tree[iid].parent; 
    }
}

int main(){
    int n;
    cin >> n;
    tree.resize(n);

    rep(i, n){
        int id, childNum, childId;
        cin >> id >> childNum;
        rep(j, childNum){
            cin >> childId;

            tree[id].children.push_back(childId);
            tree[childId].parent = id;
        }
    }
    
    rep(i, n){
        calDepth(i);
    }

    rep(i, n){
        printf("node %d: parent = %d, depth = %d, ",
            i, tree[i].parent, tree[i].depth
        );
        
        if(tree[i].parent == -1)
            cout << "root, ";
        else if (tree[i].children.size() > 0)
            cout << "internal node, ";
        else
            cout << "leaf, ";

        cout << "[";
        int cnum = tree[i].children.size();
        rep(j, cnum)
            cout << tree[i].children[j] << (j < cnum-1?", ":"");
        cout << "]\n";
    }

}
