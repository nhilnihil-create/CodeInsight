#include <iostream>
#include <vector>
#include <queue>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N * 3);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;

        G[u - 1].push_back(v - 1 + N);
        G[u - 1 + N].push_back(v - 1 + N * 2);
        G[u - 1 + N * 2].push_back(v - 1);
    }

    int S, T;
    std::cin >> S >> T;

    std::vector<int> dist(N * 3, -1);
    dist[S - 1] = 0;
    std::queue<int> que;
    que.push(S - 1);
    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int v : G[u]) {
            if (dist[v] >= 0)
                continue;
            dist[v] = dist[u] + 1;
            que.push(v);
        }
    }

    int ans = dist[T - 1];
    if (ans >= 0)
        ans /= 3;
    std::cout << ans << "\n";
}