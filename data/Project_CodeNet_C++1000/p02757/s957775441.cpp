#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  ll amari[220000];
  map<ll,ll> mp;
  ll ten = 10LL;
  if(p==2 || p==5) {
    ll ans = 0LL;
    rep(i,s.size()) {
      string t = "";
      t += s[i];
      ll m = stoi(t);
      if(m%p == 0) ans += (i+1);
    }
    cout << ans << endl;
    return 0;
  }
  reverse(s.begin(),s.end());
  rep(i,s.size()) {
    string t = "";
    t += s[i];
    ll m = stoi(t);
    if(i==0) {
      amari[i] = m%p;
      mp[amari[i]]++;
      continue;
    }
    amari[i] = (amari[i-1] + m*ten)%p;
    ten *= 10LL;
    ten %= p;
    mp[amari[i]]++;
  }
  ll ans = 0LL;
  mp[0]++;
  for(auto p : mp) {
    ll v = p.second;
    ans += v*(v-1)/2;
  }
  cout << ans << endl;
  return 0;
}