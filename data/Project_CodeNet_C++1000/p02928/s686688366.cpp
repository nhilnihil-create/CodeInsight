#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll n, k, ans = 0, tot0 = 0, tot1 = 0, t;
  cin >> n >> k;
  vector<ll> a(n), cnt(n), cnts(n);
  rep(i, n) cin >> a[i];
  rep(i, n) for (int j = i + 1; j < n; ++j) if (a[i] > a[j]) tot0++;
  rep(i, n) rep(j, n) if (a[i] > a[j]) tot1++;

  ans += tot0 * k;
  ans %= MOD;
  t = (k - 1) * k / 2 % MOD;
  t *= tot1;
  t %= MOD;
  ans += t;
  ans %= MOD;

  cout << ans << endl;
  return 0;
}
