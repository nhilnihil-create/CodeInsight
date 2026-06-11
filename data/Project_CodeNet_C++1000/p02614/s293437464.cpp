#include <bits/stdc++.h>

const int MAX_RC = 7;
int R, C, K;
char grid[MAX_RC][MAX_RC];
char gg[MAX_RC][MAX_RC];

int count() {
  int ans = 0;
  for (int r = 0; r < R; ++r)
    for (int c = 0; c < C; ++c)
      ans += (gg[r][c] == '#');
  return ans;
}

int main() {
  scanf("%d %d %d ", &R, &C, &K);
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      grid[r][c] = getchar();
    }
    scanf(" ");
  }
  int cc = 0;
  int mm = (1 << (R + C)) - 1;
  for (int i = 0; i <= mm; ++i) {
    memcpy(gg, grid, sizeof(gg));
    for (int r = 0; r < R; ++r) {
      if (!(i & (1 << r))) continue;
      for (int c = 0; c < C; ++c)
        gg[r][c] = 'r';
    }
    for (int r = 0; r < C; ++r) {
      if (!(i & (1 << (r+R)))) continue;
      for (int c = 0; c < R; ++c)
        gg[c][r] = 'r';
    }
    if (count() == K) cc++;
  }
  printf("%d\n", cc);
}
