#include <cstdio>
#include <cstring>

using namespace std;

int n;
int a[1043][1043];
int cur[1043];
bool vis[1043];
int ans;

int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    cur[i] = 1;
    for (int j = 1; j < n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  bool flag = true;
  while (flag) {
    flag = false;
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
      int j = a[i][cur[i]];
      if (vis[i] || vis[j]) continue;
      if (i == a[j][cur[j]]) {
        flag = true;
        ++cur[i];
        ++cur[j];
        vis[i] = true;
        vis[j] = true;
        continue;
      }
    }
    if (flag) {
      ++ans;
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      if (cur[i] != n) {
        printf("-1\n");
        return 0;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
