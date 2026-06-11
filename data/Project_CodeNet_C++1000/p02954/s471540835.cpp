#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<bool> RL(n - 1);
  rep(i, n - 1) {
    if (s[i] == 'R' && s[i + 1] == 'L') {
      RL[i] = true;
    }
  }
  vector<int> c(1, 1);
  rep(i, n - 1) {
    if (s[i] == s[i + 1]) {
      c.back()++;
    } else {
      c.emplace_back(1);
    }
  }
  vector<int> ans(n, 0);
  for (int i = 0, j = 0; i < n - 1; i++) {
    if (RL[i]) {
      ans[i] += (c[j] + 1) / 2;
      ans[i + 1] += c[j] / 2;
      j++;
      ans[i] += c[j] / 2;
      ans[i + 1] += (c[j] + 1) / 2;
      j++;
    }
  }
  rep(i, n) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}