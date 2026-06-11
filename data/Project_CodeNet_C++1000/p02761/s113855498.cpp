#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,m; cin >> n >> m;
  vector<bool> b(n,true);
  vector<ll> ans(n,0);
  
  rep(j, m){
    ll s,c; cin >> s >> c;
    if(n != 1 && s == 1 && c == 0){
      cout << -1 << endl; return 0;}
    if(b[s-1]){
      b[s-1] = false; ans[s-1] = c;}
    else if(!b[s-1] && ans[s-1] != c){
      cout << -1 << endl; return 0;}
  }
  
  if(n == 2 && ans[n-2]==0)
    ans[n-2]++;
  if(n == 3 && ans[n-3]==0)
    ans[n-3]++;
  rep(i, n)
    cout << ans[i];
  cout << endl;
}