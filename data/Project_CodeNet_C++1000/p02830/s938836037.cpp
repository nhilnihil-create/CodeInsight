#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s, t;
  cin >> n >> s >> t;
  string ans;
  rep(i, 2 * n) {
    if (i % 2 == 0) {
      ans += s[i / 2];
    } else {
      ans += t[i / 2];
    }
  }
  cout << ans;
  return 0;
}
