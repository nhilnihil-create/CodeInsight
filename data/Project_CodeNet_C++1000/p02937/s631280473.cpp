#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.size();

  vector<vector<int>> v(26);
  for (int i = 0; i < n; ++i) {
    v[s[i] - 'a'].push_back(i);
  }

  int pos = 0;
  long long ans = 0;
  for (int i = 0; i < t.size(); ++i) {
    int j = t[i] - 'a';
    if (v[j].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
    auto iter = lower_bound(v[j].begin(), v[j].end(), pos);
    if (iter == v[j].end()) {
      i -= 1;
      pos = 0;
      ans += n;
    } else {
      pos = *iter + 1;
    }
  }
  ans += pos;

  cout << ans << endl;
}