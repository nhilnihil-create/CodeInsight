#include <bits/stdc++.h>
#define reg register
#define ll long long
#define ull unsigned long long
using namespace std;
ll x, k, d;
void work() {
  scanf("%lld%lld%lld", &x, &k, &d), x = abs(x);
  ll tmp = min(x / d, k);
  k -= tmp, x -= tmp * d;
  if(k % 2 == 0) printf("%lld\n", x);
  else printf("%lld\n", d - x);
}
signed main() {
  int _ = 1;
  // scanf("%d", &_);
  while(_--) {
    work();
  }
  return 0;
}