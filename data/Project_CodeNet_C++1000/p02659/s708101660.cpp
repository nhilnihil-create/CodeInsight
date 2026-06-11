#include <bits/stdc++.h>

int main() {
  int64_t a;
  double b;
  scanf("%lld %lf", &a, &b);
  __int128 aa = a;
  __int128 bb = round(b * 100);
  printf("%lld\n", int64_t((aa * bb) / 100));
}
