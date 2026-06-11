#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  rep(i, n) sort(s[i].begin(), s[i].end());
  map<string, int> mp;
  rep(i, n) ++mp[s[i]];
  ll ans = 0;
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    ans += (ll)(*itr).second * ((*itr).second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}