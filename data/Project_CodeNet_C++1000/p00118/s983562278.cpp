#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_H = 100;
const int MAX_W = 100;

int H, W;
char orchard[MAX_H][MAX_W + 1];
bool passed[MAX_H][MAX_W];

void dfs(int h, int w, const char c)
{
  if (h < 0 || H <= h) return;
  if (w < 0 || W <= w) return;
  if (orchard[h][w] != c) return;
  if (passed[h][w]) return;

  passed[h][w] = true;

  dfs(h + 1, w, c);
  dfs(h - 1, w, c);
  dfs(h, w + 1, c);
  dfs(h, w - 1, c);

  return;
}

int solve()
{
  int res = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (!passed[i][j]) {
        res++;
        dfs(i, j, orchard[i][j]);
      }
    }
  }

  return res;
}

int main()
{
  while (true) {
    scanf("%d %d", &H, &W);

    if (H == 0 && W == 0) break;

    for (int i = 0; i < H; i++) {
      scanf("%s", orchard[i]);
      orchard[i][W] = 0;

      for (int j = 0; j < W; j++) {
        passed[i][j] = false;
      }
    }

    printf("%d\n", solve());
  }

  return 0;
}
