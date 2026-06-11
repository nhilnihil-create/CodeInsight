#include <stdio.h>
#include <algorithm>
#include <set>
#include <utility>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, ans = 0, now;
  scanf("%lld", &n);
  pair<ll, ll> p[n];
  for(i = 0; i < n; ++i) scanf("%lld", &p[i].first), p[i].second = i;
  multiset<ll> s;
  multiset<ll>::iterator it, it2;
  s.insert(-1), s.insert(-1), s.insert(n), s.insert(n);
  sort(p, p + n);
  s.insert(p[n - 1].second);
  for(i = n - 2; i >= 0; --i) {
    it = s.lower_bound(p[i].second);
    it2 = it;
    now = -(*it);
    it++;
    now += *it;
    it2--;
    ans += now * (p[i].second - *it2) * p[i].first;
    it--;
    now = *it2;
    it2--;
    now -= *it2;
    ans += now * (*it - p[i].second) * p[i].first;
    s.insert(p[i].second);
  }
  printf("%lld", ans);
  return 0;
}