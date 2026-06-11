#include <stdio.h>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j = 0, n, m, ans = 0;
  scanf("%lld%lld", &n, &m);
  pair<ll, ll> p[n];
  priority_queue<ll> q;
  for(i = 0; i < n; ++i) scanf("%lld%lld", &p[i].first, &p[i].second);
  sort(p, p + n);
  for(i = 1; i <= m; ++i) {
    for(; j < n; ++j) {
      if(p[j].first <= i) {
        q.push(p[j].second);
        continue;
      }
      break;
    }
    if(q.size()) ans += q.top(), q.pop();
  }
  printf("%lld", ans);
  return 0;
}