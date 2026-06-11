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
  int j = m;
  for (int i = 0; i <= n; ++i) {
    ll r = k-c[i];
    if (r < 0) break;
    while (r < d[j]) --j;
    ans = max(ans, i+j);
  }
  cout << ans << endl;
}