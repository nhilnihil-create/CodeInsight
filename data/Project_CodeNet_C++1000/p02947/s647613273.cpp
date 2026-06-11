#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  map<string,ll> m;
  ll ans = 0;
  rep(i,n) {
    string s; cin >> s;
    sort(s.begin(),s.end());
    if (m.count(s) != 0) ans += m[s];
    m[s]++;
  }
  cout << ans << endl;
  return 0;
}