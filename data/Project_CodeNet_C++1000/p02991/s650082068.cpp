#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

int bfs(const vvi& G, int s, int t) {
    int n = G.size();

    vvb seen(n, vb(3, false));
    seen[s][0] = true;

    queue<pair<int, int>> q;
    q.emplace(s, 0);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int v = curr.first;
        int depth = curr.second;

        for (int u : G[v]) {
            // 終了．
            if (u == t && (depth + 1) % 3 == 0) { return (depth + 1) / 3; }
            if (seen[u][(depth + 1) % 3]) { continue; }

            seen[u][(depth + 1) % 3] = true;
            q.emplace(u, depth + 1);
        }
    }
    return -1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vvi G(n);
    rep(_, 0, m) {
        int u, v;
        cin >> u >> v;
        G[u - 1].push_back(v - 1);
    }
    int s, t;
    cin >> s >> t;
    cout << bfs(G, s - 1, t - 1) << endl;

    return 0;
}