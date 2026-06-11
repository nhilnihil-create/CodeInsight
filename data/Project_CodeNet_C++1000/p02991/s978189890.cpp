#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, m;
    cin >> n >> m;
    vec g[300010];
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u*3].push_back(v*3+1);
        g[u*3+1].push_back(v*3+2);
        g[u*3+2].push_back(v*3+0);
    }
    int s, t;
    cin >> s >> t;
    --s; --t;
    s *= 3;
    t *= 3;

    vec dist(n*3, INF);
    dist[s] = 0;

    queue<int> que;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto&& c : g[v]) {
            if (dist[c] == INF) {
                dist[c] = dist[v] + 1;
                que.push(c);
            }
        }
    }

    if (dist[t] == INF) {
        cout << "-1" << endl;
        exit(0);
    }
    else {
        cout << dist[t]/3 << endl;
    }
    return 0;
}