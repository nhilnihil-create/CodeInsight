#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string ans(n, 'z');
  while (m--) {
    int s;
    char c;
    cin >> s >> c;
    s--;
    if (s == 0 && c == '0') {
      if (n == 1) {
        cout << 0 << '\n';
      } else {
        cout << -1 << '\n';
      }
      return 0;
    }
    if (ans[s] == 'z') {
      ans[s] = c;
    } else if (ans[s] != c) {
      cout << -1 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == 'z') {
      if (n > 1 && i == 0) {
        ans[0] = '1';
      } else {
        ans[i] = '0';
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
