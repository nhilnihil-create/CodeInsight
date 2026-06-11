#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define f1(i, a, b) for (int i = a; i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  ll n;
  cin >> n;
  ll ans = 1e18;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i != 0) continue;
    ll j = n / i;
    ans = min(ans, i + j - 2);
  }
  cout << ans << '\n';
  return 0;
}