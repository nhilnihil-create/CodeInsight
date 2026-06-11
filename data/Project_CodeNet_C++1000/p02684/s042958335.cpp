#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pdd;

#define INF 0x7f7f7f
#define mem(a,b) memset(a , b , sizeof(a))
#define FOR(i, x, n) for(int i = x;i <= n; i++)
// const ll mod = 1e9 + 7;
// const int maxn = 1e5 + 10;
// const double eps = 1e-6;

const int maxn = 2e5 + 10;
int a[maxn], vis[maxn];
int ans, pos;
vector<int> v;

void dfs(int u)
{
    ans++;
    vis[u] = ans;
    v.push_back(u);
    if(!vis[a[u]])
        dfs(a[u]);
    else
    {
        pos = vis[a[u]];
        v.push_back(a[u]);
        return ;
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    for(int i = 1;i <= n; i++)
        cin >> a[i];
    dfs(1);
    if(k < v.size())
        cout << v[k] << endl;
    else
    {
        k -= v.size();
        ll len = v.size() - pos;
        cout << v[pos + k % len] << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
#ifdef FZT_ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
#endif
    return 0;
}
