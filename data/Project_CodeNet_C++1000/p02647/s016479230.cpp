#include <stdio.h>
typedef long long ll; 

ll max(ll a, ll b) {
  return a > b ? a : b;
}

ll min(ll a, ll b) {
  return a < b ? a : b;
}

int main(void) {
  ll i, j, n, k;
  scanf("%lld%lld", &n, &k);
  ll a[n], sum[n + 1];
  for(i = 0; i < n; ++i) scanf("%lld", &a[i]);
  bool flg = true;
  for(i = 0; i < k && flg; ++i) {
    flg = false;
    for(j = 0; j < n; ++j) sum[j] = 0;
    for(j = 0; j < n; ++j) sum[max(0, j - a[j])]++, sum[min(n, j + a[j] + 1)]--;
    a[0] = sum[0];
    if(a[0] != n) flg = true;
    for(j = 1; j < n; ++j) {
      a[j] = a[j - 1] + sum[j];
      if(a[j] != n) flg = true;
    }
  }
  for(i = 0; i < n; ++i) printf("%lld ", a[i]);
  return 0;
}