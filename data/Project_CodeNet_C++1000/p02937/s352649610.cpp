#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;

  map<char, vector<int>> idx;
  rep(i, s.size()) { idx[s[i]].push_back(i); }

  int cur = -1, loop = 0;
  rep(i, t.size()) {
    auto it = lower_bound(idx[t[i]].begin(), idx[t[i]].end(), cur + 1);
    if (it != idx[t[i]].end()) {
      cur = *it;
    } else {
      cur = -1;
      auto it = lower_bound(idx[t[i]].begin(), idx[t[i]].end(), cur + 1);
      if (it == idx[t[i]].end()) {
        cout << -1 << endl;
        return 0;
      }
      cur = *it;
      ++loop;
    }
  }

  ll ans = (ll)loop * s.size() + cur + 1;
  cout << ans << endl;
  return 0;
}
