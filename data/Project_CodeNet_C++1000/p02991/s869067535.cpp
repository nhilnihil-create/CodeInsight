#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    Graph<int> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }

    int S, T;
    cin >> S >> T;
    S--, T--;

    vector<vector<int>> dist(N, vector<int>(3, 1e9));
    queue<pii> que;
    dist[S][2] = 0;
    que.push({S, 2});
    while (!que.empty()) {
        pii p = que.front();
        que.pop();
        int v = p.first, n1 = p.second;
        for (auto nv : G[v]) {
            int n2 = (n1 + 1) % 3;
            if (dist[nv][n2] < 1e9)
                continue;
            dist[nv][n2] = dist[v][n1] + (n2 == 0);
            que.push({nv, n2});
        }
    }

    cout << (dist[T][2] < 1e9 ? dist[T][2] : -1) << endl;
    return 0;
}
