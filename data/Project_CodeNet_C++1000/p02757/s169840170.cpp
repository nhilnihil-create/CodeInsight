#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n, p;
  string s;
  cin >> n >> p >> s;

  reverse(s.begin(),s.end());

  if(p == 2 || p == 5) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      if((s[i] - '0') % p == 0) cnt += (n - i);
    }
    cout << cnt << '\n';
    return 0;
  }

  map<int,int> mp;
  mp[0] = 1;

  int ten = 1;
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    tmp = (s[i] - '0') * ten + tmp;
    tmp %= p;
    ten *= 10;
    ten %= p;
    mp[tmp]++;
  }
  int ans = 0;
  for (auto it : mp) {
    ans += (it.second) * (it.second - 1) / 2;
  }
  cout << ans << '\n';
  return 0;
}