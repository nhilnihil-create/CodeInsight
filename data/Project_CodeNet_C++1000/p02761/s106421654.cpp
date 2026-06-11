#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> s(m);
  vector<char> c(m);
  for (int i = 0; i < m; i++) cin >> s[i] >> c[i];

  string ans = "1";
  if (n > 1) {
    for (int i = 1; i < n; i++) ans += "0";
  } else {
    ans = "0";
  }

  for (int i = 0; i < m; i++) ans[s[i] - 1] = c[i];

  bool ok = true;
  for (int i = 0; i < m; i++) ok &= (ans[s[i] - 1] == c[i]);
  if (n > 1 && ans[0] == '0') ok = false;

  if (ok) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}
