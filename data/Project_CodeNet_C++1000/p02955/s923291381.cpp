#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(void) {
  ll i, j, k, n, sum = 0, now, t, t2;
  scanf("%lld%lld", &n, &k);
  ll a[n];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]), sum += a[i];
  vector<ll> d;
  multiset<ll>::iterator it;
  for(i = 1; i * i <= sum; ++i) if(!(sum % i)) d.push_back(i);
  for(i = d.size() - 1; i >= 0; --i) if(d[i] * d[i] != sum) d.push_back(sum / d[i]);
  for(i = d.size() - 1; i >= 0; --i) {
    multiset<ll> s;
    now = 0;
    for(j = 0; j < n; ++j) if(a[j] % d[i]) s.insert(a[j] % d[i]);
    while(s.size()) {
      t = *s.begin();
      s.erase(s.begin());
      now += t;
      while( t ) {
        it = s.end();
        it--;
        t2 = *it;
        s.erase(it);
        if(t + t2 < d[i]) s.insert(t + t2), t = 0;
        else t -= d[i] - t2;
      }
    }
    if(now <= k) {
      printf("%lld", d[i]);
      return 0;
    }
  }
  return 0;
}