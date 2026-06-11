#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, n, k, s;
  scanf("%lld%lld%lld", &n, &k, &s);
  if(s == 1e9) {
    for(i = 0; i < k; ++i) printf("%lld ", s);
    for(; i < n; ++i) printf("%lld ", 1);
  } else {
    for(i = 0; i < k; ++i) printf("%lld ", s);
    for(; i < n; ++i) printf("%lld ", s + 1);
  }
  return 0;
}