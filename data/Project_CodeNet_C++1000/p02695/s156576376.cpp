#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(q), b(q), c(q), d(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--, b[i]--;
  }
  vector<int> h(n + m - 1, 1);
  for (int i = 0; i < m - 1; i++) {
    h[i] = 0;
  }
  int ans = 0;
  do {
    vector<int> A;
    int cnt = 1;
    for (auto&& e : h) {
      if (e == 0) {
        cnt++;
      } else {
        A.push_back(cnt);
      }
    }
    int score = 0;
    for (int i = 0; i < q; i++) {
      if (A[b[i]] - A[a[i]] == c[i]) {
        score += d[i];
      }
    }
    ans = max(ans, score);
  } while (next_permutation(h.begin(), h.end()));
  cout << ans << '\n';
  return 0;
}
