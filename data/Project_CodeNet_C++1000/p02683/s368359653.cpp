#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

int main() {
  int n, m, x; scanf("%d%d%d", &n, &m, &x);
  std::vector<int> c(n);
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for(int i = 0; i < n; i++) {
    scanf("%d", &c[i]);

    for(auto& v: a[i]) scanf("%d", &v);
  }

  int ans = 1 << 30;
  for(int i = 0; i < (1 << n); i++) {
    int cost = 0;
    std::vector<int> tmp(m);
    for(int j = 0; j < n; j++) {
      if(i >> j & 1) continue;
      cost += c[j];
      for(int k = 0; k < m; k++) tmp[k] += a[j][k];
    }

    if(*min_element(begin(tmp), end(tmp)) >= x) ans = std::min(ans, cost);
  }
  if(ans == 1 << 30) ans = -1;

  printf("%d\n", ans);
  return 0;
}
