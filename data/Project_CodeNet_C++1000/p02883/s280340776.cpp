#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, mi = -1, ma = 1e12 + 1, now, cnt;
  scanf("%lld%lld", &n, &k);
  ll a[n], f[n];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for(i = 0; i < n; ++i) scanf("%lld", &f[i]);
  sort(a, a + n), sort(f, f + n, greater<ll>());
  while(mi != ma - 1) {
    now = (mi + ma) / 2, cnt = 0;
    for(i = 0; i < n; ++i) if(a[i] * f[i] > now) cnt += a[i] - (now / f[i]);
    if(cnt > k) mi = now;
    else ma = now;
  }
  printf("%lld", ma);
  return 0;
}