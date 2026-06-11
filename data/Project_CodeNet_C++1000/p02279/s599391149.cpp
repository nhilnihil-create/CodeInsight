#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

#define MAX 100005
#define INF INT_MAX

typedef long long ll;
typedef pair<int, int> P;

class Node
{
public:
    int parent;
    int depth;
    vector<int> child;
    Node(int id) { parent = -1; depth = 0; }
};

void dfs(int v, int p, vector<Node>& nodes)
{
    for (int c : nodes[v].child) {
        nodes[c].depth = nodes[v].depth + 1;
        dfs(c, v, nodes);
    }
}

int main(int, char**)
{
    int n;
    cin >> n;

    vector<Node> nodes;
    rep(i,n) nodes.push_back(Node(i));
    rep(i,n) {
        int id, k;
        cin >> id >> k;
        rep(j,k) {
            int tmp;
            cin >> tmp;
            nodes[id].child.push_back(tmp);
            nodes[tmp].parent = id;
        }
    }
    auto itr = find_if(nodes.begin(), nodes.end(), [] (Node& nd) { return nd.parent == -1; } );
    int root = distance(nodes.begin(), itr);
    dfs(root, -1, nodes);

    rep(i,n) {
        Node nd = nodes[i];
        cout << "node " << i << ": parent = " << nd.parent << ", depth = " << nd.depth << ", ";
        if (nd.parent == -1) cout << "root";
        else if (nd.child.size() == 0) cout << "leaf";
        else cout << "internal node";
        cout << ", [";
        int s = nd.child.size();
        rep (j,s) { if(j) cout << ", "; cout << nd.child[j]; }
        cout << "]" << endl;
    }

    return 0;
}
