#include <bits/stdc++.h>
using namespace std;

int R,C;
int f[10][10000];
bool flag[10];
int ans = 0;

int cnt(void) {
  int res = 0;
  for (int i = 0; i < C; i++) {
    int tmp = 0;
    for (int j = 0; j < R; j++) {
      if (!f[j][i] && flag[j] || f[j][i] && !flag[j]) tmp++;
    }
    res += max(tmp, R-tmp);
  }
  return res;
}

void solve(int num) {
  if (num == R) {
    ans = max(cnt(), ans); return;
  }
  flag[num] = false;
  solve(num+1);
  flag[num] = true;
  solve(num+1);
}

int main() {
  while (cin >> R >> C) {
    if (R == 0 || C == 0) break;
    ans = 0;
    for (int r = 0; r < R; r++)
      for (int c = 0; c < C; c++) cin >> f[r][c];
    solve(0);
    cout << ans << endl;
  }
}