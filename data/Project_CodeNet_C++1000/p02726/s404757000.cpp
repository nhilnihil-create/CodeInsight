#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, x, y;
  std::cin >> n >> x >> y;

  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  g[x - 1].push_back(y - 1);
  g[y - 1].push_back(x - 1);

  std::vector<int> res(n + 7, 0);
  for (int s = 0; s < n; ++s) {
    std::vector<int> dist(n, -1);
    std::queue<int> pool;
    dist[s] = 0;
    pool.push(s);
    while (!pool.empty()) {
      int v = pool.front();
      pool.pop();
      for (auto nv : g[v]) {
        if (dist[nv] >= 0)
          continue;
        dist[nv] = dist[v] + 1;
        pool.push(nv);
      }
    }
    for (auto &v : dist)
      res[v] += 1;
  }
  for (int k = 1; k < n; ++k)
    std::cout << res[k] / 2 << std::endl;
}
