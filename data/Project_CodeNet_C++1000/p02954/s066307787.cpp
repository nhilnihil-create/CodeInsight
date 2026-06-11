#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<int> rl, lr;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R' && s[i + 1] == 'L') {
      rl.emplace_back(i);
    } else if (s[i] == 'L' && s[i + 1] == 'R') {
      lr.emplace_back(i);
    }
  }
  int nrl = (int)rl.size();
  vector<int> ans(n, 0);
  lr.insert(lr.begin(), -1);
  lr.emplace_back(n - 1);
  for (int i = 0; i < nrl; i++) {
    ans[rl[i]] += (rl[i] - lr[i] + 1) / 2;
    ans[rl[i] + 1] += (rl[i] - lr[i]) / 2;
    ans[rl[i]] += (lr[i + 1] - rl[i]) / 2;
    ans[rl[i] + 1] += (lr[i + 1] - rl[i] + 1) / 2;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}