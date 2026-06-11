#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int in[N] , sz[N] , nxt;

int dfs(int node , int par = -1) {
    in[node] = nxt++;
    sz[node] = 1;
    for (int child : adj[node])
        if (child != par)
            sz[node] += dfs(child  , node);
    return sz[node] ;
}

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int n , q;
    cin >> n >> q;

    for (int i = 0 ;i < n - 1 ;i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    vector<int> ans(n + 1 , 0);
    while (q--) {
        int u , inc;
        cin >> u >> inc;
        ans[in[u]] += inc;
        ans[in[u] + sz[u]] -= inc;
    }

    for (int i = 1 ;i < n ;i++)
        ans[i] += ans[i - 1];

    for (int i = 1 ;i <= n ;i++)
        cout << ans[in[i]] << ' ';
}
