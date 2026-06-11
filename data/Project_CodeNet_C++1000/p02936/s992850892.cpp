// https://atcoder.jp/contests/abc138/tasks/abc138_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> G(N + 1);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  vector<int> ans(N + 1);
  while (Q--) {
    int p, q;
    cin >> p >> q;
    ans[p] += q;
  }

  queue<int> que;
  que.push(1);
  // 後戻りしないようにする
  bitset<200001> bs;
  bs.set(1);
  while (!que.empty()) {
    int t = que.front();
    que.pop();
    for (auto &x : G[t]) {
      if (!bs[x]) {
        bs.set(x);
        ans[x] += ans[t];
        que.push(x);
      }
    }
  }
  FOR(i, 1, N + 1) { cout << ans[i] << (i == N ? "\n" : " "); }

  return 0;
}
