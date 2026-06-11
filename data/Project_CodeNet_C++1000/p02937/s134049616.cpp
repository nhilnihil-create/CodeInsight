#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  string s, t;
  cin >> s >> t;

  map<char, vector<int>> idx;
  rep(i, s.size()) { idx[s[i]].push_back(i); }
  rep(i, s.size()) { idx[s[i]].push_back(i + s.size()); }

  int cur = -1;
  ll ans = 0;
  rep(i, t.size()) {
    if (idx.count(t[i]) == 0) {
      cout << "-1" << endl;
      return 0;
    }

    cur = *lower_bound(idx[t[i]].begin(), idx[t[i]].end(), cur + 1);
    if (cur >= (int)s.size() - 1) {
      ans += s.size();
      cur -= s.size();
    }

    // auto it = lower_bound(idx[t[i]].begin(), idx[t[i]].end(), cur + 1);
    // if (it != idx[t[i]].end()) {
    //   cur = *it;
    // } else {
    //   cur = -1;
    //   auto it = lower_bound(idx[t[i]].begin(), idx[t[i]].end(), cur + 1);
    //   if (it == idx[t[i]].end()) {
    //     cout << -1 << endl;
    //     return 0;
    //   }
    //   cur = *it;
    //   ++loop;
    // }
  }

  // ll ans = (ll)loop * s.size() + cur + 1;
  cout << ans + cur + 1 << endl;
  return 0;
}
