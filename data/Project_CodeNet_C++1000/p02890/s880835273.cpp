#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[--x]++;
  }
  sort(a.begin(), a.end());
  vector<long long> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }
  for (int k = 1; k <= n; k++) {
    int lo = 0, hi = n + 1;
    while (hi - lo > 1) {
      int mid = (lo + hi) >> 1;
      int ltm = upper_bound(a.begin(), a.end(), mid) - a.begin();
      long long tot = sum[ltm] + 1LL * (n - ltm) * mid;
      if (tot >= 1LL * mid * k) lo = mid;
      else hi = mid;
    }
    cout << lo << '\n';
  }
  return 0;
}