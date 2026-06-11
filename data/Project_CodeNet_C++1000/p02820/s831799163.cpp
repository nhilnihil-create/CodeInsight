#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  int ans = 0;
  map<char, bool> flag;
  for (int i = 0; i < n; i++) {
    if (i >= k && t[i] == t[i - k]) {
      t[i] = 'x';
      continue;
    }
    if (t[i] == 'r') {
      ans += p;
    } else if (t[i] == 's') {
      ans += r;
    } else {
      ans += s;
    }
  }
  cout << ans << '\n';
  return 0;
}
