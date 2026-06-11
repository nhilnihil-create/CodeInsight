#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  using ll = long long;
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll ans = 0;
  for (int i = 0; i < 1000; i++) {
    string si = to_string(i);
    if (si.length() == 1)
      si = "00" + si;
    else if (si.length() == 2)
      si = "0" + si;
    auto ok = [&](string si) {
      bool ok1 = 0, ok2 = 0, ok3 = 0;
      int i1, i2;
      for (int i = 0; i < n; i++) {
        if (si[0] == s[i]) {
          ok1 = 1;
          i1 = i;
          break;
        }
      }
      if (ok1 == 0) return false;
      for (int i = n - 1; i > i1; i--) {
        if (si[2] == s[i]) {
          ok2 = 1;
          i2 = i;
          break;
        }
      }
      if (ok2 == 0) return false;
      for (int i = i1 + 1; i < i2; i++) {
        if (si[1] == s[i]) {
          ok3 = 1;
          break;
        }
      }
      if (ok3) {
        return true;
      } else {
        return false;
      }
    };
    if (ok(si)) ans++;
  }
  cout << ans << '\n';
  return 0;
}
