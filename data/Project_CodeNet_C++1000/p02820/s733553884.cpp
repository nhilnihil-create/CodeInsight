#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  int r, s, p;
  cin >> r >> s >> p;
  string t;
  cin >> t;
  ll ans = 0;
  vector<bool> lose(n, false);
  for (int i = 0; i < n; ++i) {
    if (i - k >= 0 && t[i] == t[i - k] && !lose[i - k]) {
      lose[i] = true;
      continue;
    }
    if (t[i] == 'r') {
      ans += p;
    } else if (t[i] == 's') {
      ans += r;
    } else if (t[i] == 'p') {
      ans += s;
    }
  }
  cout << ans << endl;
  return 0;
}
