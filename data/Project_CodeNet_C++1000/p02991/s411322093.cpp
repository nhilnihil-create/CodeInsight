#include <climits>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(3 * N);
  rep(i, M) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    G[3 * u + 0].emplace_back(3 * v + 1);
    G[3 * u + 1].emplace_back(3 * v + 2);
    G[3 * u + 2].emplace_back(3 * v + 0);
  }

  int S, T;
  cin >> S >> T;
  --S;
  --T;
  vector<int> visit(3 * N, INT_MAX);
  visit[3 * S] = 0;
  queue<pair<int, int>> que;
  que.emplace(0, 3 * S);
  while (!que.empty()) {
    int step, u;
    tie(step, u) = que.front();
    que.pop();
    if (visit[u] < step) continue;
    int nstep = step + 1;
    for (auto v : G[u]) {
      if (visit[v] <= nstep) continue;
      visit[v] = nstep;
      que.emplace(nstep, v);
    }
  }
  if (visit[3 * T] == INT_MAX)
    cout << -1 << endl;
  else
    cout << visit[3 * T] / 3 << endl;
  return 0;
}
