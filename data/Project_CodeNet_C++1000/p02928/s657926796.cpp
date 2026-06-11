#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> l(n, 0), r(n, 0);
  rep(i, n) rep(j, n) {
    if (a[i] <= a[j]) continue;
    if (j < i) ++l[i];
    if (i < j) ++r[i];
  }

  ll cl = (ll)k * (k-1) / 2 % MOD;
  ll cr = (ll)k * (k+1) / 2 % MOD;
  ll ans = 0;
  rep(i, n) {
    ans += cl * l[i] + cr * r[i];
    ans %= MOD;
    if (ans < 0) ans += MOD;
  }
  cout << ans << endl;
  return 0;
}