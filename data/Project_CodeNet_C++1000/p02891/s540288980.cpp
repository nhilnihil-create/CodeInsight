#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  vector<ll> cnts;
  ll cur = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      cnts.push_back(cur);
      cur = 1;
    } else {
      cur++;
    }
  }
  cnts.push_back(cur);

  if (cnts.size() == 1) {
    ll ans = (ll)n * k / 2;
    cout << ans << '\n';
    return 0;
  }

  ll ans = 0;
  for (int i = 0; i < cnts.size(); ++i) {
    ans += (cnts[i] / 2 * k);
  }
  

  if (s[0] == s.back()) {
    ll sub = (cnts[0] / 2) + (cnts.back() / 2) - ((cnts[0] + cnts.back()) / 2);
    ans -= (sub * (k - 1));
  }
  cout << ans << '\n';
  return 0;
}
