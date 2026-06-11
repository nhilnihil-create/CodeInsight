#include <bits/stdc++.h>

using namespace std;

const int64_t INF = INT64_C(1) << 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
    P[i]--;
  }
  vector<int64_t> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  int64_t res = -INF;
  for (int i = 0; i < N; i++) {
    int cur = i, cnt = 0;
    int64_t tot = 0;
    while (true) {
      tot += C[cur];
      cur = P[cur];
      cnt++;
      if (cur == i) break;
    }
    int c = 0;
    int64_t t = 0;
    while (true) {
      c++;
      t += C[cur];
      if (c > K) break;
      int n = (K - c) / cnt;
      res = max(res, t + max(INT64_C(0), tot) * n);
      cur = P[cur];
      if (cur == i) break;
    }
  }
  cout << res << '\n';
  return 0;
}
