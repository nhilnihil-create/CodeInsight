#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, ans = 0, now;
  scanf("%lld", &n);
  ll a[n], b[n];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for(i = 0; i < n; ++i) scanf("%lld", &b[i]);
  priority_queue< pair<ll, ll> > q;
  pair<ll, ll> p;
  for(i = 0; i < n; ++i) {
    if(a[i] > b[i]) {
      printf("-1");
      return 0;
    }
    if(a[i] < b[i]) q.push(make_pair(b[i], i));
  }
  while(q.size()) {
    p = q.top(), q.pop();
    now = b[(p.second + 1) % n] + b[(p.second + n - 1) % n];
    if(now > p.first) {
      printf("-1");
      return 0;
    }
    ans += (p.first - a[p.second]) / now;
    b[p.second] = p.first - (p.first - a[p.second]) / now * now;
    if(b[p.second] != a[p.second]) q.push(make_pair(b[p.second], p.second));
  }
  printf("%lld", ans);
  return 0;
}