#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ff first
#define ss second
#define pb push_back
#define print(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int bexp(int a, int b, int mod)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (res * a) % mod;

        a = (a * a) % mod; 
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int N = 100010;
const int mod = 998244353;

struct comp {
    bool operator() (const pair<int, int> a, const pair<int, int> b) const
    {
        int d1 = a.ss - a.ff, d2 = b.ss - b.ff;
        return ((d1 > d2) || (d1 == d2 && a.ff < b.ff));
    }
};

vector<int> g[N];
int visited[N] = {};

void dfs(int v) {
    visited[v] = 1;
    for (int k : g[v]) {
        if (!visited[k])
            dfs(k);
    }
}

int32_t main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int ans = 0;
    for (int i = 1; i < n + 1; ++i)
    {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }

    cout << ans - 1 << endl;
    return 0;
}