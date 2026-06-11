#include <stdio.h>
typedef long long ll;

ll a[1000][1000], d[1000][1000], n, s[1000][1000];
bool flg[1000][1000], flg2[1000][1000];

ll dfs(ll b, ll c) {
  if(flg2[b][c]) return -1;
  ll now = 0, t;
  flg2[b][c] = flg2[c][b] = true;
  if(s[b][c]) {
    t = 0;
    if(flg[b][a[b][s[b][c] - 1]]) {
      t = dfs(b, a[b][s[b][c] - 1]);
      if(t == -1) return -1;
    } else t = d[b][a[b][s[b][c] - 1]];
    if(now < t) now = t;
  }
  if(s[c][b]) {
    t = 0;
    if(flg[c][a[c][s[c][b] - 1]]) {
      t = dfs(c, a[c][s[c][b] - 1]);
      if(t == -1) return -1;
    } else t = d[c][a[c][s[c][b] - 1]];
    if(now < t) now = t;
  }
  flg[b][c] = flg[c][b] = false;
  d[b][c] = d[c][b] = now + 1;
  flg2[b][c] = flg2[c][b] = false;
  return now + 1;
}

int main(void) {
  ll i, j, k, ans = 0;
  scanf("%lld", &n);
  for(i = 0; i < n; ++i) for(j = 0; j < n - 1; ++j) scanf("%lld", &a[i][j]), s[i][--a[i][j]] = j;
  for(i = 0; i < n; ++i) for(j = 0; j < n; ++j) flg[i][j] = true, flg2[i][j] = false;
  for(i = 0; i < n; ++i) flg[i][i] = false;
  for(i = 0; i < n; ++i) for(j = 0; j < n; ++j) if(i != j) {
    if(flg[i][j]) {
      if(dfs(i, j) == -1) {
        printf("-1");
        return 0;
      }
    }
  }
  for(i = 0; i < n; ++i) for(j = 0; j < n; ++j) if(i != j && d[i][j] > ans) ans = d[i][j];
  printf("%lld", ans);
  return 0;
}