#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll MOD = 1000000007;
const int MAX = 100005;
static const int INF = 1 << 15;
int n, k;
int used[100005];
vector<int> G[100005];

ll ans = 0; 
ll node[100005];

ll fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long Per(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}
 
void dfs(int v) {
    for (int i = 0; i < G[v].size(); i++) {
        if (node[G[v][i]] == 0) {
            node[v] += 1;
            dfs(G[v][i]);
        }
    }
    return;
}

void bfs() {
    queue<int> q;
    q.push(0);
    for (int i = 0; i < n; i++) {
        used[i] = INF;
    }
    used[0] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == 0) {
            ans += Per(k, node[0]);
            ans %= MOD;
        }
        else {
            ans *= Per(k - 2, node[u]);
            ans %= MOD;
        }
        for (int v: G[u]) {
            if (used[v] != INF) continue;
            used[v] = 0;
            q.push(v);
        }
    }
}
 
int main() {
    int u, v;
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    COMinit();
    for (int i = 0; i < n; i++) node[i] = 0;
    node[0] = 1;
    dfs(0);
    bfs();
    cout << ans << endl;
    return 0;
}