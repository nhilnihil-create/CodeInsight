#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  //cin.tie(nullptr);
  //ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  map<string, int> mp;
  rep(i, n) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ++mp[s];
  }
  
  auto fac = [&](ll n) {
    ll res = 0;
    for(ll a = 1; a <= n-1; ++a) {
      res += a;
    }
    return res;
  };
  
  ll ans = 0;
  for(auto i = mp.begin(); i != mp.end(); ++i) {
    ans += fac(i->second);
  }
  cout << ans << endl;
  return 0;
}