#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int src, dest;
    cin >> src >> dest;
    src--;
    dest--;
    graph[src].push_back(dest);
  }

  int s, t;
  cin >> s >> t;
  s--;
  t--;

  int ans = -1;
  vector<vector<int>> dists(n, vector<int>(3, -1));
  queue<pair<int, int>> q;
  q.push({s, 0});
  while (!q.empty()) {
    int node_idx = q.front().first, dist = q.front().second;
    q.pop();

    if (dists[node_idx][dist % 3] != -1) {
      continue;
    }

    dists[node_idx][dist % 3] = dist;
    for (auto &neighbor : graph[node_idx]) {
      q.push({neighbor, dist + 1});
    }
  }

  cout << (dists[t][0] < 0 ? dists[t][0] : dists[t][0] / 3) << '\n';

  return 0;
}
