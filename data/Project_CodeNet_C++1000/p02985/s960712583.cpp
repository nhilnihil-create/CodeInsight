#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll mul_mod(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;

// 深さ優先探索
vector<bool> seen;  // 既に見たことがある頂点か記録
ll dfs(const Graph &G, int v, ll k, ll pre, bool isfirst = true) {
    seen[v] = true;
    ll ret = k;
    ll npre = (isfirst) ? 0 : 1;
    ll tmp = k - 1 + pre;
    // cout << v + 1 << " " << tmp << " " << npre << " " << ret << endl;

    for (auto e : G[v]) {
        if (!seen[e.to]) {  // 訪問済みでなければ探索
            ret = mul_mod(ret, dfs(G, e.to, tmp, npre, false));
            npre++;
            tmp--;
        }
    }
    // cout << v + 1 << " " << ret << endl;
    if (k == 0) return 0;
    return ret;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    int N;
    ll K;
    cin >> N >> K;

    Graph G(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back({b});
        G[b].push_back({a});
    }

    seen.assign(N, false);  // 初期化
    cout << dfs(G, 0, K, 0) << endl;

    return 0;
}
