#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, d, ans = 0, a;
  scanf("%lld%lld%lld", &n, &d, &a);
  d *= 2;
  pair<ll, ll> m[n], p;
  ll sum[n + 1], now = 0;
  for(i = 0; i < n; ++i) scanf("%lld%lld", &m[i].first, &m[i].second), m[i].second = (m[i].second + a - 1) / a;
  sort(m, m + n);
  for(i = 0; i <= n; ++i) sum[i] = 0;
  for(i = 0; i < n; ++i) {
    now += sum[i];
    if(m[i].second > now) {
      ans += m[i].second - now;
      p = make_pair(m[i].first + d, 1e9);
      sum[upper_bound(m, m + n, p) - m] -= m[i].second - now;
      now = m[i].second;
    }
  }
  printf("%lld", ans);
  return 0;
}