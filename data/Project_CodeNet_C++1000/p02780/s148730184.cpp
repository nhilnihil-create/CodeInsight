#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> sum(n);
  for (int i = 0; i < k; i++) {
    sum[0] += p[i];
  }
  int smax = sum[0];
  for (int i = 0; i < n - k; i++) {
    sum[i + 1] = sum[i] - p[i] + p[i + k];
    smax = max(smax, sum[i + 1]);
  }
  int ans = smax + k;
  if (ans % 2 == 0) {
    cout << ans / 2 << '\n';
  } else {
    cout << to_string(ans / 2) + ".5" << '\n';
  }
  return 0;
}