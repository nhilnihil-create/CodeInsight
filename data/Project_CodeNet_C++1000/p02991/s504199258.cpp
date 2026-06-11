#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

vector<vector<int>> G;
int S, T;

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
    }
    cin >> S >> T;
    --S, --T;

    vector<vector<int>> dist(N, vector<int>(3, -1));
    dist[S][0] = 0;
    queue<pair<int, int>> q;
    q.push({S, 0});

    while (!q.empty()) {
        int v = q.front().first;
        int p = q.front().second;
        q.pop();
        for (auto nv : G[v]) {
            int np = (p + 1) % 3;
            if (dist[nv][np] == -1) {
                dist[nv][np] = dist[v][p] + 1;
                q.push({nv, np});
            }
        }
    }
    if (dist[T][0] == -1)
        cout << -1 << endl;
    else
        cout << dist[T][0] / 3 << endl;
}