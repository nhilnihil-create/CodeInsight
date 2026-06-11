#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  ll ans = 0;
  rep(i, n) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    auto itr = mp.find(s);
    if ( itr != mp.end()) {
      ans += mp[s];
      mp[s] += 1;
    } else {
      mp[s] = 1;
    }
  }
  cout << ans << '\n';
  return 0;
}