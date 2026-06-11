#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <vector>
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
int n, a[20];
int x[20][20], y[20][20];
int vis[20], ans = 0;

void dfs(int u) {
  if (u == n+1) {
    int sum = 0;
    for (int i=1; i <= n; i++) {
      if (vis[i]) {
        for (int j=1; j <= a[i]; j++) {
          if (y[i][j] == 0 && vis[x[i][j]] == 1) {
            return;
          }
          if (y[i][j] == 1 && vis[x[i][j]] == 0) {
            return;
          }
        }
        sum++;
      }
    }

    ans = std::max(ans, sum);
    return;
  }

  vis[u] = 0;
  dfs(u+1);
  vis[u] = 1;
  dfs(u+1);
}

int main (int argc, char **argv) {
  std::cin >> n;
  for (int i=1; i <= n; i++) {
    std::cin >> a[i];
    for (int j=1; j <= a[i]; j++) {
      std::cin >> x[i][j] >> y[i][j];
    }
  }

  dfs(1);
  std::cout << ans << std::endl; 
  return 0;
}
