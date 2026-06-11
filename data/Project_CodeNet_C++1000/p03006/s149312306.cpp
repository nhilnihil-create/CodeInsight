#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; i++) cin >> x.at(i) >> y.at(i);
  if (N == 1) { cout << 1 << endl; return 0; }
  int ans = 100;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      int p = x.at(i) - x.at(j);
      int q = y.at(i) - y.at(j);
      int cnt = 0;
      for (int s = 0; s < N; s++) {
        for (int t = 0; t < N; t++) {
          int a = x.at(s) - x.at(t);
          int b = y.at(s) - y.at(t);
          if (a == p && b == q) cnt++;
        }
      }
      ans = min(ans, N - cnt);
    }
  }
  cout << ans << endl;
}