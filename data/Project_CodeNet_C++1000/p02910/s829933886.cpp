#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  string s;
  cin >> s;
  string ans = "Yes";
  rep(i, s.size()) {
    if (i % 2 == 0) {
      if (s[i] == 'R') continue;
      if (s[i] == 'U') continue;
      if (s[i] == 'D') continue;
      ans = "No";
    } else {
      if (s[i] == 'L') continue;
      if (s[i] == 'U') continue;
      if (s[i] == 'D') continue;
      ans = "No";
    }
  }
  cout << ans << '\n';
  return 0;
}