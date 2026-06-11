#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5, mod = 1e9 + 7;
int k;
ll ans, root;
bool vis[N];
vector<int> v[N];

void dfs(int node)
{
    vis[node] = true;
    ll beg = k - 1;
    if (root != node)
        beg--;
    for (auto it: v[node])
        if (!vis[it])
        {
            ans = (ans * max(beg--, 0LL)) % mod;
            dfs(it);
        }
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ans = k;
    for (int i = 1; i <= n; i++)
        if (v[i].size() == 1 && !vis[i])
            root = i,
            dfs(i);
    cout << ans;
    return 0;
}