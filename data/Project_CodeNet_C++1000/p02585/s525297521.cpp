#include <bits/stdc++.h>
#define reg register
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXN = 5010;
const ll INF = numeric_limits<ll>::max();
int n, k;
ll p[MAXN], c[MAXN], t[MAXN], d[MAXN], md[MAXN];
void work() {
  scanf("%d%d", &n, &k);
  int now;
  for(reg int i = 1; i <= n; ++i) scanf("%lld", &p[i]);
  for(reg int i = 1; i <= n; ++i) scanf("%lld", &c[i]);
  for(reg int i = 1; i <= n; ++i) {
    now = p[i];
    d[i] = c[now], t[i] = 1, md[i] = -INF;
    md[i] = max(md[i], d[i]);
    while(now != i) {
      ++t[i], now = p[now], d[i] += c[now];
      md[i] = max(md[i], d[i]);
    }
  }
  ll ans = -INF, tmp;
  int cnt = 0;
  for(reg int i = 1; i <= n; ++i) {
    if(k / t[i] > 0) {
      ans = max(ans, md[i]);
      if(k % t[i] == 0) {
        ans = max(ans, (k / t[i] - 1) * d[i] + md[i]);
        continue;
      }
    }
    tmp = k / t[i] * d[i], now = p[i], tmp += c[now];
    ans = max(ans, tmp), cnt = 1;
    while(k % t[i] != cnt) {
      ++cnt, now = p[now], tmp += c[now];
      ans = max(ans, tmp);
    }
  }
  printf("%lld\n", ans);
}
signed main() {
  int _ = 1;
  // scanf("%d", &_);
  while(_--) {
    work();
  }
  return 0;
}

