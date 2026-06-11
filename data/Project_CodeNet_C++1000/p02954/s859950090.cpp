#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  // 左からと右から数える
  int n = s.length();
  vector<int> ans(n);
  int odd = 0; int even = 0;
  rep(i, n) {
    if (s[i] == 'R') {
      if (i&1) odd++;
      else even++;
    } else {
      if (i&1) {
        ans[i] += odd;
        ans[i-1] += even;
      } else {
        ans[i] += even;
        ans[i-1] += odd;
      }
      odd = 0; even = 0;
    }
  }
  //rep(i, n) cout << ans[i] << ' ';
  //cout << '\n';
  odd = 0; even = 0;
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == 'L') {
      if (i&1) odd++;
      else even++;
    } else {
      if (i&1) {
        ans[i] += odd;
        ans[i+1] += even;
      } else {
        ans[i] += even;
        ans[i+1] += odd;
      }
      odd = 0; even = 0;
    }    
  }
  rep(i, n) cout << ans[i] << ' ';
  return 0;
}