/*
* @Author: dnhirapara
* @Problem: abc177_d
* @Time: 11-September-2020 : ( 16:17:57 )
*/
#include <bits/stdc++.h>

using namespace std;

/************defination************/

#define endl "\n"
#define logger(x) cout << __LINE__ << ": " << #x << " -> " << (x) << endl;
#define ll long long int
#define ull unsigned long long int

vector<ll> g[200005];
vector<bool> vis(200005, 0);

ll max_len = 0;

void dfs(ll node, ll lvl)
{
    vis[node] = true;
    for (auto i : g[node])
    {
        // logger(i);
        if (!vis[i])
        {
            dfs(i, lvl + 1);
            max_len++;
        }
    }
    // max_len = max(lvl, max_len);
}

//@time comp :
//@space comp :
int main()
{
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // cin.ignore(); must be there when using getline(cin, s)
    ll tc = 1;
    //cin >> tc;
    while (tc--)
    {
        ll n, m;
        cin >> n >> m;
        // logger(n);
        ll u, v;
        for (int i = 0; i <= n; i++)
        {
            vis[i] = false;
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ll maxi = LLONG_MIN;
        for (ll i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                max_len = 0;
                dfs(i, 0);
                // logger(max_len);
                maxi = max(max_len, maxi);
            }
        }
        cout << maxi + 1 << endl;
    }
    return 0;
}