#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  while (true) {
    int n; cin >> n;
    if (n == 0) return 0;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int res = 1e9;
    for (int i = 0; i < n - 1; i++) res = min(res, a[i + 1] - a[i]);
    cout << res << '\n';
  }
  return 0;
}
