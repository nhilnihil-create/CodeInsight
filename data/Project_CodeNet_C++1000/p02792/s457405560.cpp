#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  map<P, int> mp;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    mp[P(s.front(), s.back())]++;
  }

  ll ans = 0;
  for (auto x : mp) {
    for (auto y : mp) {
      P xp = x.first;
      P yp = y.first;
      if (xp.first == yp.second && xp.second == yp.first)
        ans += x.second * y.second;
    }
  }
  cout << ans << endl;
  return 0;
}
