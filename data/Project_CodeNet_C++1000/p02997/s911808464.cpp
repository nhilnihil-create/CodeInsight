#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, now;
  scanf("%lld%lld", &n, &k);
  if(k > (n - 1) * (n - 2) / 2) {
    printf("-1");
    return 0;
  }
  now = (n - 1) * (n - 2) / 2;
  vector<ll> a, b;
  for(i = 1; i < n; ++i) a.push_back(1), b.push_back(i + 1);
  for(i = 2; now > k; ++i) {
    for(j = i; j < n && now > k; ++j) --now, a.push_back(i), b.push_back(j + 1);
  }
  printf("%lld\n", a.size());
  for(i = 0; i < a.size(); ++i) printf("%lld %lld\n", a[i], b[i]);
  return 0;
}