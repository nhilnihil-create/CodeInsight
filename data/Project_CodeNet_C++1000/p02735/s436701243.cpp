#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int inf = 1e9;
char s[maxn][maxn];
int mem[maxn][maxn];
int h, w;

bool inside(int i, int j) {
  return (0 <= i && i < h) && (0 <= j && j < w);
}
int dp(int i, int j) {
  if(i == h-1 && j == w-1) return 0;
  int &ans = mem[i][j];
  if(ans != -1) return ans;
  ans = inf;
  if(inside(i + 1, j)) ans = min(ans, dp(i + 1, j) + (s[i][j] == '.' && s[i + 1][j] == '#'));
  if(inside(i, j + 1)) ans = min(ans, dp(i, j + 1) + (s[i][j] == '.' && s[i][j + 1] == '#'));
  return ans;
}
int main() {
  scanf("%d %d", &h, &w);
  for(int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  memset(mem, -1, sizeof mem);
  printf("%d\n", dp(0, 0) + (s[0][0] == '#'));
  return 0;
}
