#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int,int>;

const int N = 4010;

int n; char s[N];
int a[N], cnt[3][N];

int main() { 
  scanf("%d %s", &n, s);
  for(int i = 0; i < n; i++) {
    if(s[i] == 'R') a[i + 1] = 0;
    else if(s[i] == 'G') a[i + 1] = 1;
    else a[i + 1] = 2;
    for(int k : {0, 1, 2})
      cnt[k][i + 1] = cnt[k][i];
    cnt[a[i + 1]][i + 1]++;
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) if(a[i] != a[j]) {
      int k = 0;
      while(a[i] == k || a[j] == k) k++;
      int got = cnt[k][n] - cnt[k][j];
      if(j + (j - i) <= n && a[j + (j - i)] == k) 
        got--;
      ans += got;
    }
  } printf("%lld\n", ans);
  return 0;
}
