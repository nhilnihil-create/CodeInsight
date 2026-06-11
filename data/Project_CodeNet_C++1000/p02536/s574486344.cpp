#include <bits/stdc++.h>
const int mmax = 1e6;
using namespace std;
long long n, m, ans;
bool vis[mmax];
vector <int> adj[mmax];
void dfs(int u)
{
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs(v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            dfs(i);
            ans++;
        }
    cout << --ans;
    return 0;
}
