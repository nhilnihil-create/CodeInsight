#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, h, w, ans = 3, now;
  scanf("%lld%lld", &h, &w);
  char s[h][w + 10];
  ll cnt[4][h][w];
  for(i = 0; i < h; ++i) scanf("%s", s[i]);
  for(i = 0; i < h; ++i) for(j = 0; j < w; ++j) {
    cnt[0][i][j] = cnt[1][i][j] = 1;
    if(s[i][j] == '#')  cnt[0][i][j] = cnt[1][i][j] = 0;
    else {
      if(i) cnt[0][i][j] = cnt[0][i - 1][j] + 1;
      if(j) cnt[1][i][j] = cnt[1][i][j - 1] + 1;
    }
  }
  for(i = h - 1; i >= 0; --i) for(j = w - 1; j >= 0; --j) {
    cnt[2][i][j] = cnt[3][i][j] = 1;
    if(s[i][j] == '#')  cnt[2][i][j] = cnt[3][i][j] = 0;
    else {
      if(i != h - 1) cnt[2][i][j] = cnt[2][i + 1][j] + 1;
      if(j != w - 1) cnt[3][i][j] = cnt[3][i][j + 1] + 1;
    }
  }
  for(i = 0; i < h; ++i) for(j = 0; j < w; ++j) {
    now = 0;
    for(k = 0; k < 4; ++k) now += cnt[k][i][j];
    if(ans < now) ans = now;
  }
  printf("%lld", ans - 3);
  return 0;
}