#include <cstdio>
using ll = long long;
int main() {
  ll n; scanf("%lld", &n);
  for (ll i = 0; i < n; ++i) {
    for (ll j = i+1; j < n; ) {
      ll d = i ^ j;
      ll ans = 0;
      for (ll l = d & -d; l; ++ans) l >>= 1;
      printf("%lld%c", ans, " \n"[++j==n]);
    }
  }
}
