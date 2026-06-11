#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

int main() {
  int a, b, c, k; scanf("%d%d%d%d", &a, &b, &c, &k);

  int ans = 0;
  if(k) {
    ans += std::min(a, k) * 1;
    k -= std::min(a, k);
  }
  if(k) {
    ans += std::min(b, k) * 0;
    k -= std::min(b, k);
  }
  if(k) {
    ans += std::min(c, k) * -1;
    k -= std::min(c, k);
  }

  printf("%d\n", ans);
  return 0;
}
