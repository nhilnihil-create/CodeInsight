#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj(200005);
bool vis[200005];
int sz;

void dfs(int u) {
    vis[u] = 1;
    sz++;
    for (int v: adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            sz = 0;
            dfs(i);
            ans = max(ans, sz);
        }
    }

    cout << ans << '\n';

    return 0;
}
