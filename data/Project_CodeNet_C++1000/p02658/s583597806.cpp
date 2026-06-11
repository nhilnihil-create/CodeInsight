#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  __int128 mul = 1;
  bool isz = false;
  bool isb = false;
  for (int i = 0; i < n; ++i) {
    int64_t a;
    scanf("%lld", &a);
    __int128 aa = a;
    mul = mul * aa;
    if (a == 0) {
      isz = true;
      break;
    }
    if (mul > 1000000000000000000LL) {
      isb = true;
    }
  }
  printf("%lld\n", isz ? 0 : (isb ? -1 : int64_t(mul)));
}
