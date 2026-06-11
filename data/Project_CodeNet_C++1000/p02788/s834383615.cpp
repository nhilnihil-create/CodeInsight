#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, D, A;
  cin >> N >> D >> A;
  vector<pair<int, int>> M(N);
  for (auto &m : M) {
    cin >> m.first >> m.second;
  }
  sort(M.begin(), M.end());
  vector<int> right_m(N);
  for (int i = 0; i < N - 1; i++) {
    auto r = make_pair(M[i].first + 2 * D + 1, 0);
    right_m[i] = upper_bound(M.begin(), M.end(), r) - M.begin() - i;
  }
  vector<long long> damage(N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (i > 0) {
      damage[i] += damage[i - 1];
    }
    M[i].second -= damage[i];
    if (M[i].second <= 0) {
      continue;
    }
    long long count = (M[i].second + A - 1) / A;
    ans += count;
    damage[i] += count * A;
    if (i + right_m[i] < N) {
      damage[i + right_m[i]] -= count * A;
    }
  }
  cout << ans << endl;

  return 0;
}
/* vim:set fdm=marker: */
