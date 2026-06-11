#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--; v--;
    G.at(u).push_back(v);
  }
  int S, T; cin >> S >> T;
  S--; T--;
  const int INF = 1000000007;
  vector<vector<int>> D(N, vector<int>(3, INF));
  D.at(S).at(0) = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(S, 0));
  while (!q.empty()) {
    int cur = q.front().first;
    int d = q.front().second;
    q.pop();
    int nd = (d + 1) % 3;
    for (int nx : G.at(cur)) {
      if (D.at(nx).at(nd) != INF) continue;
      D.at(nx).at(nd) = D.at(cur).at(d) + 1;
      q.push(make_pair(nx, nd));
    }
  }
  if (D.at(T).at(0) != INF) cout << D.at(T).at(0) / 3 << endl;
  else cout << -1 << endl;
}