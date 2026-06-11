#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
const ll MOD = 1e9 + 7;

ll n, k, ans = 1;
vector<int> conn[N];
int par[N], c[N];

void dfs(int v, int p) {
    par[v] = p;
    for (auto u : conn[v]) {
        if (u != p) {
            ++c[v];
            dfs(u, v);
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }
 
    dfs(0, -1);

    queue<pair<int, int>> q;
    q.push({0, k});

    while (!q.empty()) {
        pair<int, int> v = q.front(); 
        q.pop();
        ans = ((ans % MOD) * (v.second % MOD)) % MOD;
        // cout << v.first << ' ' << ans << '\n';
        ll pos = k - 1;
        if (par[v.first] != -1) --pos;
        for (auto u : conn[v.first]) {
            if (u == par[v.first]) continue;
            q.push({u, pos--});
            pos = max(0ll, pos);
        }
    }
    
    cout << ans % MOD;
}
