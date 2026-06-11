#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, n, x, l, ans = 0, now = -1e12;
  scanf("%lld", &n);
  pair<ll, ll> p[n];
  for(i = 0; i < n; ++i) {
    scanf("%lld%lld", &x, &l);
    p[i].first = x + l;
    p[i].second = x - l;
  }
  sort(p, p + n);
  for(i = 0; i < n; ++i) if(now <= p[i].second) now = p[i].first, ans++;
  printf("%lld", ans);
  return 0;
}