#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n, k, l, to[N];
vector<ll>v;
bool vis[N];
void dfs(int u)
{
    vis[u] = 1;
    v.push_back(u);
    if(!vis[to[u]]) dfs(to[u]);
    else            l = to[u];
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> to[i];
    dfs(1);
    if(k < v.size())
        cout << v[k];
    else
    {
        vector<ll>t;
        bool f = 0;
        for(auto &it : v)
        {
            if(it == l) f = 1;
            if(f)   t.push_back(it);
            else    --k;
        }
        cout << t[k % t.size()];
    }
    return 0;
}
