#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; ll k; cin >> s >> k;
  ll sn = s.size();
  ll sum = 0, ans = 0;
  int l = 0, r = sn - 1, lc = 0, rc = 0, mc = 0;
  if (s[l] == s[r]) {
    while(s[l] == s[0] && l < sn) {lc++; l++;}
    while(s[r] == s[sn-1] && r >= 0) {rc++; r--;}
    if (l == sn) {
      ans = sn * k / 2;
      cout << ans << endl;
      return 0;
    }
    if (lc+rc == 2) mc = 1;
    else mc = (lc+rc)/2;
    ans += lc / 2;
    ans += rc / 2;
    ans += mc * (k-1);
  }
  for (int i = l; i<=r; i++) {
    int cnt = 1;
    while(i+1<=r && s[i] == s[i+1]) {
      i++;
      cnt++;
    }
    sum += cnt / 2;
  }
  ans += sum * k;
  cout << ans << endl;
  return 0;
}