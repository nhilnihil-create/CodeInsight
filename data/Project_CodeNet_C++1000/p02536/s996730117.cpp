#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int mod = 1000000007;
const int N = 1e5 + 1;
vector<int> g[N];
int vis[N];

/*
Idea--



*/

void dfs(int node)
{
    vis[node] = 1;
    for (int c : g[node])
    {
        if (!vis[c])
            dfs(c);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        // int a[n];
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i)
            vis[i] = 0;
        int ct = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[i])
            {
                dfs(i);
                ct++;
            }
        }
        cout << ct - 1 << "\n";
    }
}