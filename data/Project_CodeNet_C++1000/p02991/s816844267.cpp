// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
const int INF = 1000000007;

// 頂点の状態を管理する。pair<最短距離, pair<頂点番号、到達時間のMOD3>>
using P = pair<int, pair<int, int>>;
using Graph = vector<vector<int>>;

int mod = 3;

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        // G[v].push_back(u);
    }

    int S, T;  // start, end
    cin >> S >> T;
    S--; T--;

    // dist[v][k] ... 頂点vにp(mod)回で到達する際の最短距離
    vector<vector<int>> dist(N, vector<int>(mod, INT_MAX));

    // 初期値のセット
    dist[S][0] = 0;

    // 最短頂点候補を保持するキュー
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, {S, 0}));

    // 拡張ディクストラ
    while (!que.empty()) {
        auto p = que.top();
        que.pop();

        int v = p.second.first;
        int k = p.second.second;

        if (dist[v][k] < p.first) continue;

        for (auto nv : G[v]) {
            int nk = (k + 1) % mod;
            if (dist[nv][nk] > dist[v][k] + 1) {
                dist[nv][nk] = dist[v][k] + 1;
                que.push(P(dist[nv][nk], {nv, nk}));
            }
        }
    }

    if (dist[T][0] != INT_MAX) cout << dist[T][0] / 3 << endl;
    else cout << -1 << endl;
}