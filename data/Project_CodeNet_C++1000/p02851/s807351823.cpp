#include <stdio.h>
#include <set>
#include <utility>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, m, ans = 0;
  scanf("%lld%lld", &n, &k);
  if(k == 1) {
    printf("0");
    return 0;
  }
  ll sum[n + 1], a[n];
  sum[0] = 0;
  set< pair<ll, ll> > s;
  set< pair<ll, ll> >::iterator it;
  pair<ll, ll> p;
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]), sum[i + 1] = (sum[i] + --a[i]) % k;
  if(k <= n) {
    for(i = 1; i < k; ++i) {
      p = make_pair(sum[i], 1);
      if((it = s.lower_bound(p)) != s.end() && (*it).first == sum[i]) p.second = (*it).second + 1, s.erase(it);
      s.insert(p);
    }
    for(i = 0; i < n; ++i) {
      p = make_pair(sum[i], 1);
      if((it = s.lower_bound(p)) != s.end() && (*it).first == sum[i]) ans += (*it).second;
      p = make_pair(sum[i + 1], 1);
      it = s.lower_bound(p);
      p.second = (*it).second - 1;
      s.erase(it);
      if(p.second) s.insert(p);
      if(i + k <= n) {
        p = make_pair(sum[i + k], 1);
        if((it = s.lower_bound(p)) != s.end() && (*it).first == sum[i + k]) p.second = (*it).second + 1, s.erase(it);
        s.insert(p);
      }
    }
  } else {
    for(i = 1; i <= n; ++i) {
      p = make_pair(sum[i], 1);
      if((it = s.lower_bound(p)) != s.end() && (*it).first == sum[i]) p.second = (*it).second + 1, s.erase(it);
      s.insert(p);
    }
    for(i = 0; i < n; ++i) {
      p = make_pair(sum[i], 1);
      if((it = s.lower_bound(p)) != s.end() && (*it).first == sum[i]) ans += (*it).second;
      p = make_pair(sum[i + 1], 1);
      it = s.lower_bound(p);
      p.second = (*it).second - 1;
      s.erase(it);
      if(p.second) s.insert(p);
    }
  }
  printf("%lld", ans);
  return 0;
}