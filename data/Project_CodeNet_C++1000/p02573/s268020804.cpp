#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[200005];
int vis[200005];
int cnt = 0;

void dfs(int v)
{
    cnt++;
    vis[v] = 1;
    for (auto u : adj[v])
    {
        if (!vis[u])
            dfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int p, q;
        cin >> p >> q;
        adj[p].push_back(q), adj[q].push_back(p);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
        ans = max(cnt, ans);
        cnt = 0;
    }
    cout << ans;
    return 0;
}