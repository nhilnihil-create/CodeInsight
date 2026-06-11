#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    X--, Y--;
    vector<vector<int>> graph(N);
    rep(i, N - 1) {
        int j = i + 1;
        graph[i].emplace_back(j);
        graph[j].emplace_back(i);
    }
    graph[X].emplace_back(Y);
    graph[Y].emplace_back(X);

    auto bfs = [&](int s) {
        vector<int> dist(graph.size(), -1);
        queue<int> que;
        auto push = [&](int v, int cost) {
            if(dist[v] != -1) return;
            dist[v] = cost;
            que.emplace(v);
        };
        push(s, 0);
        while(!que.empty()) {
            int cur = que.front(); que.pop();
            for(auto &to : graph[cur]) push(to, dist[cur] + 1);
        }
        return dist;
    };

    vector<vector<int>> dist(N);
    rep(i, N) dist[i] = bfs(i);
    vector<int> ans(N);
    rep(i, N) for(int j = i + 1; j < N; ++j) {
        ans[dist[i][j]]++;
    }
    for(int i = 1; i < N; ++i) cout << ans[i] << '\n';
    return 0;
}
