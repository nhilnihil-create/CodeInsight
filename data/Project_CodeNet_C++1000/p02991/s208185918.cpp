#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, INF = 1e9 + 7;

int n, m, s, t;
vector<int> g[N];
int dist[N][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    cin >> s >> t;
    s--;
    t--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) dist[i][j] = INF;
    }
    dist[s][0] = 0;
    deque<pair<int, int>> q{{s, 0}};
    while (!q.empty()) {
        int u = q.front().first, kek = q.front().second;
        q.pop_front();
        for (auto v : g[u]) {
            if (dist[u][kek] + 1 < dist[v][(kek + 1) % 3]) {
                dist[v][(kek + 1) % 3] = dist[u][kek] + 1;
                q.emplace_back(v, (kek + 1) % 3);
            }
        }
    }
    cout << (dist[t][0] == INF ? -1 : dist[t][0] / 3);
    return 0;
}
