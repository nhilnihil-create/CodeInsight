#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

class Node {
    public:
        vector<int> children;
        vector<int> edge_value;
        int value;
        int parent;
};

class Tree {
    public:
        int root;
        int node_num;
        vector<Node> node;
        
        Tree(vector<vector<int>> hen, int r) {
            root = r;
            node_num = hen.size();
            node = vector<Node>(hen.size());
            
            queue<int> v;
            v.push(root);
            node[root].parent = -1;
            int edge_num = 0;
            while(!v.empty()) {
                int tyoten = v.front();
                node[tyoten].value = tyoten;
                v.pop();
                for (int i = 0; i < hen[tyoten].size(); i++) {
                    int child = hen[tyoten][i];
                    if (child != node[tyoten].parent) {
                        node[tyoten].children.push_back(child);
                        node[tyoten].edge_value.push_back(edge_num);
                        edge_num++;
                        node[child].parent = tyoten;
                        v.push(child);
                    }
                }
            }
        }
};

long long mod_nPr(long long n, long long r, long long mod) {
    if (r <= 0)
        return 1;
    else if (n <= 0)
        return 0;
    else {
        long long result = 1;
        for (int i = n; i > n-r; i--)
            result = (result * i) % mod;
        return result;
    }
}

int main(void){
    ll MOD = 1000000007;
    ll n, k;
    cin >> n >> k;
    vector<vector<int>> hen(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        hen[a-1].push_back(b-1);
        hen[b-1].push_back(a-1);
    }
    
    Tree tree(hen, 0);
    queue<int> que;
    que.push(0);
    ll ans = k;
    while(!que.empty()) {
        int local_tree_node = que.front();
        que.pop();
        if (tree.node[local_tree_node].parent != -1)
            ans = ans * mod_nPr(k-2, tree.node[local_tree_node].children.size(), MOD) % MOD;
        else
            ans = ans * mod_nPr(k-1, tree.node[local_tree_node].children.size(), MOD) % MOD;
        
        for (int i = 0; i < tree.node[local_tree_node].children.size(); i++)
            que.push(tree.node[local_tree_node].children[i]);
    }
    cout << ans << endl;
}