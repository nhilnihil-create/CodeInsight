#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;
int dist[300005];

int main() {
  // bfs、各頂点の状態数３
  int N, M;
  cin >> N >> M;
  vector<int> graph[3*N];  // 0-indexed
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    a *= 3; b *= 3;
    rep(j, 3) {
      graph[a+j].push_back(b+((j+1)%3));
      // graph[b+j].push_back(a+((j+1)%3));
    }
  }
  queue<P> que;
  rep(i, 3*N) dist[i] = INF;
  auto push = [&](int x, int d) {
    if (dist[x] < d) return;
    dist[x] = d;
    for (auto next : graph[x]) {
      if (dist[next] == INF) que.push(P(next, d+1));
    }
  };
  int S, T;
  cin >> S >> T;
  --S; --T;
  S *= 3; T *= 3;
  push(S, 0);
  while (!que.empty()) {
    auto p = que.front(); que.pop();
    int x = p.first, d = p.second;
    if (dist[x] == INF) push(x, d);
  }
  int ans = dist[T];
  if (ans == INF) ans = -1;
  else ans /= 3;
  cout << ans << '\n';
  return 0;
}

// 40