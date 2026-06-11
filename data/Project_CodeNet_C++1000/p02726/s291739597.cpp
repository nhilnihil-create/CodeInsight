#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;

int main() {
  // bfsで
  int N, X, Y;
  cin >> N >> X >> Y;
  --X; --Y;
  vector<int> cnt(N);
  rep(start, N) {
    queue<int> que;
    vector<int> dist(N, INF);   // 0-indexed
    auto push = [&](int next, int d) {
      if (dist[next] != INF) return;
      dist[next] = d;
      que.push(next);
    };
    push(start, 0);
    while (!que.empty()) {
      int next = que.front(); que.pop();
      int d = dist[next];
      if (next-1>=0) push(next-1, d+1);
      if (next+1<=N) push(next+1, d+1);
      if (next == X) push(Y, d+1);
      if (next == Y) push(X, d+1);
    }
    for (int i = 0; i < N; i++) {
      cnt[dist[i]]++;
    }
  }
  rep(i, N) cnt[i] /= 2;
  for (int i = 1; i < N; i++) {
    cout << cnt[i] << '\n';
  }
  return 0;
}