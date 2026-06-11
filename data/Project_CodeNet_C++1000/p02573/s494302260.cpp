#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//FILE *fi = freopen("1.txt", "r", stdin);
//FILE *fo = freopen("1", "w", stdout);
//FILE *fi = freopen("P.inp", "r", stdin);
//FILE *fo = freopen("P.out", "w", stdout);
int n;
int m;
vector<int> a[200001];
bool used[200001];
int cnt = 0;
void dfs(int u)
{
    ++cnt;
    used[u] = true;
    for (auto v : a[u])
    {
        if (!used[v])
            dfs(v);
    }
}
int main()
{
    //------------------------------
    // Faster
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //-------------------------------
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            cnt = 0;
            dfs(i);
            ans = max(ans, cnt);
        }
    }
    cout << ans;
    return 0;
}