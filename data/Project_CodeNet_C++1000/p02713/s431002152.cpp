#include<bits/stdc++.h>
using namespace std;

int g[201][201];

int main() {
  int n; scanf("%d", &n);
  
  for(int i = 1; i <= 200; ++i) {
    for(int j = 1; j <= 200; ++j) {
      g[i][j] = g[j][i] = __gcd(i, j);
    }
  }

  int ans = 0;

  for(int a = 1; a <= n; ++a) {
    for(int b = 1; b <= n; ++b) {
      for(int c = 1; c <= n; ++c) {
        ans += g[a][g[b][c]];
      }
    }
  }
  printf("%d", ans);
  return 0;
}