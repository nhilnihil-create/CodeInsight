#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> a(n), s(n + 1);
  for (double& x : a) cin >> x;
  rep(i, 0, n) s[i + 1] = s[i] + ((a[i] * (a[i] + 1.0)) / 2.0) / a[i];

  double ans = 0;
  rep(i, 0, n - k + 1) { ans = max(ans, s[i + k] - s[i]); }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}