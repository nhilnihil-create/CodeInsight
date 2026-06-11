#include <bits/stdc++.h>
#define reg register
#define ll long long
#define ull unsigned long long
using namespace std;
string s;
int cnt[100];
void work() {
  cin >> s;
  int tot = 1, len = s.length();
  for(reg int i = 0; i < len; ++i) {
    if(s[i] == 'R') ++cnt[tot];
    if(s[i] != 'R') ++tot;
  }
  int ans = 0;
  for(reg int i = 0; i <= tot; ++i) ans = max(ans, cnt[i]);
  printf("%d\n", ans);
}
signed main() {
  int _ = 1;
  // scanf("%d", &_);
  while(_--) {
    work();
  }
  return 0;
}
