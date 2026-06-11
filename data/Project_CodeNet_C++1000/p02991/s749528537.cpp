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
    Graph<int> G(N * 3);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a = (a - 1) * 3, b = (b - 1) * 3;
        G[a].push_back(b + 1);
        G[a + 1].push_back(b + 2);
        G[a + 2].push_back(b);
    }

    int S, T;
    cin >> S >> T;
    S = (S - 1) * 3, T = (T - 1) * 3;

    vector<int> dist(3 * N, 1e9);
    queue<int> que;
    dist[S] = 0;
    que.push(S);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto nv : G[v]) {
            if (dist[nv] < 1e9)
                continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cout << (dist[T] < 1e9 ? dist[T] / 3 : -1) << endl;
    return 0;
}
