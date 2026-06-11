#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> ans(n);
  rep(i, n) {
    if (i % 2 == 0)
      ans[0] += a[i];
    else
      ans[0] -= a[i];
  }
  for (int j = 1; j < n; j++) {
    ans[j] = a[j - 1] * 2 - ans[j - 1];
  }

  rep(i, n) cout << ans[i] << endl;
  return 0;
}