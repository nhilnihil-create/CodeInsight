#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n + 1), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] >= a[i]) {
      ans += a[i];
      ans += min(a[i + 1], b[i] - a[i]);
      a[i + 1] = max(0LL, a[i + 1] - b[i] + a[i]);
    } else {
      ans += b[i];
    }
  }
  cout << ans << '\n';
}
