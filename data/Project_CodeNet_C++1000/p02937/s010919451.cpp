#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

signed main(){
  string s, t; cin >> s >> t;
  vector<vector<ll> > data(26);
  int n = s.size(), m = t.size();
  for(ll i = 0; i < n; i++) data[s[i] - 'a'].push_back(i + 1);
  for(int i = 0; i < m; i++){
    if(data[t[i] - 'a'].empty()){
      cout << -1 << endl;
      return 0;
    }
  }
  for(int i = 0; i < 26; i++) data[i].push_back(INF);
  ll now = 0, ans = 0;
  for(int i = 0; i < m; i++){
    ll x = t[i] - 'a';
    ll num = *upper_bound(data[x].begin(), data[x].end(), now);  
    if(num == INF){
      ans += n - now + data[x][0];
      now = data[x][0];
    }
    else ans += num - now, now = num;
  }
  cout << ans << endl;
}