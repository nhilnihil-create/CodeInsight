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
  int sn = s.size();
  int tn = t.size();
  vector<vector<int>> v(26);
  rep(i, 0, sn) v[s[i] - 'a'].push_back(i);

  int cur = -1;
  ll ans = 0;
  rep(i, 0, tn) {
    int ind = t[i] - 'a';
    if (v[ind].size() == 0) {
      cout << -1 << endl;
      return 0;
    }

    auto up = upper_bound(v[ind].begin(), v[ind].end(), cur);
    int x = *up;
    int id = up - v[ind].begin();
    if (id == v[ind].size()) {
      up = upper_bound(v[ind].begin(), v[ind].end(), -1);
      x = *up;
      id = up - v[ind].begin();
    }

    if (x <= cur) {
      ans += sn - (cur + 1);
      cur = -1;
    }

    ans += x - cur;
    cur = x;
  }

  cout << ans << endl;
}
