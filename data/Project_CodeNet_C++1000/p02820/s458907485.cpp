#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,k,r,s,p;
  string t;
  cin >>n>>k>>r>>s>>p>>t;
  vector<bool> ed(n,false);
  map<char,int> point;
  point['r'] = p;
  point['p'] = s;
  point['s'] = r;
  int ans = 0;
  for(int i = 0; i<n; i++) {
    ans += point[t[i]];
    if (ed[i]) continue;
    for (int j = i; j<n-k; j+=k) {
      ed[j] = true;
      if (t[j] == t[j+k]) {
        ed[j+k] = true;
        ans -= point[t[j]];
        j+=k;
      }
    }
  }
  cout << ans << endl;
  return 0;
}