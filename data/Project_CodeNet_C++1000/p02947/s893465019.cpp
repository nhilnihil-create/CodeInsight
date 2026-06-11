#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<string> s(n); rep(i,n) cin >> s[i];

  map<string,ll> mp;
  
  rep(i,n){
    sort(s[i].begin(),s[i].end());
    string t = s[i];
    mp[t]++;
  }

  ll ans = 0;
  for(auto x : mp){
    ll tmp = x.second*(x.second-1)/2;
    if(x.second > 1) ans += tmp;
  }
  cout << ans << endl;
  
  return 0;
}
