#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n;
  string s;
  cin >> n >> s;

  int R = 0;
  for (auto c : s) {
    if(c == 'R') R++;
  }

  int pref_R = 0;
  for (int i = 0; i < R; i++) {
    if(s[i] == 'R') pref_R++;
  }

  int ans = R - pref_R;
  cout << ans << '\n';
}
