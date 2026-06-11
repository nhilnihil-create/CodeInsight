#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  rep(i, n) {
    if (s[i] == 'R') cnt++;
  }
  int ans = 0;
  rep(i, cnt) {
    if (s[i] == 'W') ans++;
  }
  cout << ans << '\n';
  return 0;
}
