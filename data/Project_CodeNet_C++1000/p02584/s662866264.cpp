#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);
  ll ans;
  if (x / d > k) {
    ans = x - d * k;
  } else {
    ll y = x / d;
    k -= y;
    x -= y * d;
    if (k % 2 == 1) x = abs(x - d);
    ans = x;
  }
  cout << ans << '\n';
  return 0;
}