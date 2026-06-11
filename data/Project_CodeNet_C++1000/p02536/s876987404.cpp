#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void bfs(const Graph &G, vector<int> &dist, int s) {
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (auto nv : G[v]) {
            if (dist[nv] == -1) {
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        G[a].push_back(b), G[b].push_back(a);
    }
    int res = 0;
    vector<int> dist(N, -1);
    for (int v = 0; v < N; ++v) {
        if (dist[v] != -1) continue;
        bfs(G, dist, v);
        ++res;
    }
    cout << res - 1 << endl;
}