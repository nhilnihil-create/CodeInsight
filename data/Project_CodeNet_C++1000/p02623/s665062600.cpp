#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n), b(m);
  vector<ll> c(n+1), d(m+1);
  rep(i,n) cin >> a[i];
  rep(j,m) cin >> b[j];
  for (int i = 0; i < n; ++i) c[i+1] = c[i] + a[i];
  for (int i = 0; i < m; ++i) d[i+1] = d[i] + b[i];
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    ll rm = k-c[i];
    if (rm < 0) break;
    // cout << rm << endl;
    int l = -1, r = m+1;
    while (r - l > 1) {
      int mid = (r+l) / 2;
      if (d[mid] <= rm) l = mid;
      else r = mid;
    }
    // cout << l << endl;
    ans = max(ans, i+l);
  }
  cout << ans << endl;
}