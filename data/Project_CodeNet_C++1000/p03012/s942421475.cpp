#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> sum(n);
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    if (i == 0) {
      sum[i] = w;
    } else {
      sum[i] = sum[i - 1] + w;
    }
  }
  int ans = (int)100000;
  for (int i = 0; i < n - 1; i++) {
    ans = min(ans, abs(2 * sum[i] - sum[n - 1]));
  }
  cout << ans << '\n';
  return 0;
}
