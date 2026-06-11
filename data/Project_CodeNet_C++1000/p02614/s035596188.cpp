#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int maxn = 2e5 + 5;
char str[10][10];
int h, w, k;
int vis_row[10], vis_col[10];
int ans = 0;

void dfs_col(int u) {
    if (u == w) {
      int cnt = 0;
      for (int i=0; i < h; i++) {
        if (!vis_row[i]) {
          for (int j=0; j < w; j++) {
             if (!vis_col[j] && str[i][j] == '#') {
               cnt++;
             }
           }
        }
      }

      if (cnt == k) {
        ans++;
      }
      return;
    }

    vis_col[u] = 0;
    dfs_col(u+1);
    vis_col[u] = 1;
    dfs_col(u+1);
}

void dfs_row(int u) {
    if (u == h) {
      dfs_col(0);
      return;
    }

    vis_row[u] = 0;
    dfs_row(u+1);
    vis_row[u] = 1;
    dfs_row(u+1);
}

int main (int argc, char **argv) {
  std::cin >> h >> w >> k;
  for (int i=0; i < h; i++) {
    for (int j=0; j < w; j++) {
       std::cin >> str[i][j];
    }
  }

  dfs_row(0);
  std::cout << ans << std::endl;
  return 0;
}
