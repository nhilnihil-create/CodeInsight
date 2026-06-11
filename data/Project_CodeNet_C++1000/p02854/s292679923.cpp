#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

void chmin(int &a, int b) {
  if (a > b) a = b;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) a[i] += a[i - 1];
  }
  int ans = 1e18;
  for (int i = 0; i < n - 1; i++) {
    chmin(ans, abs(a[n - 1] - a[i] * 2));
  }
  cout << ans << '\n';
  return 0;
}
