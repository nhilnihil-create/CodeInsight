#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int mod = 1e9 + 7, ans = 1, k;
vector < int > g[maxn];

void dfs(int v, int p, int f) {
    if (f <= 0) {
        cout << 0;
        exit(0);
    }
    ans = ans * f % mod;
    int cnt = k - 1;
    if (p != 0) cnt--;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v, cnt);
            cnt--;
        }
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, k);
    cout << ans << '\n';
    return 0;
}

