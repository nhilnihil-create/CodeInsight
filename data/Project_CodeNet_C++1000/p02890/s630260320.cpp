#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, n, now, tmp;
  scanf("%lld", &n);
  ll cnt[n], a;
  vector<ll> vec;
  for(i = 0; i < n; ++i) cnt[i] = 0;
  for(i = 0; i < n; ++i) scanf("%lld", &a), cnt[--a]++;
  for(i = 0; i < n; ++i) if(cnt[i]) vec.push_back(cnt[i]);
  sort(vec.begin(), vec.end());
  ll sum[vec.size() + 1];
  sum[0] = 0;
  for(i = 0; i < vec.size(); ++i) sum[i + 1] = sum[i] + vec[i];
  for(i = 1; i <= n; ++i) {
    for(j = 1; ; ++j) {
      tmp = upper_bound(vec.begin(), vec.end(), j) - vec.begin();
      now = sum[tmp];
      now += (vec.size() - tmp) * j;
      if(i * j > now) break;
    }
    printf("%lld\n", j - 1);
  }
  return 0;
}