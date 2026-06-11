#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s, t;
  cin >> s >> t;
  int sn = s.size(), tn = t.size();
  vector<vector<int>> v(26);
  rep(i, 0, sn) v[s[i] - 'a'].push_back(i + 1);
  rep(i, 0, 26) sort(v[i].begin(), v[i].end());

  ll ans = 0;
  int last_index = 0;
  rep(i, 0, tn) {
    int ti = t[i] - 'a';
    if (v[ti].size() == 0) {
      cout << -1 << endl;
      return 0;
    }

    auto x = upper_bound(v[ti].begin(), v[ti].end(), last_index);
    if (x == v[ti].end()) {
      ans += (sn-last_index) + v[ti][0];
      last_index = v[ti][0];
    } else {
      ans += *x - last_index;
      last_index = *x;
    }
  }

  cout << ans << endl;
}
