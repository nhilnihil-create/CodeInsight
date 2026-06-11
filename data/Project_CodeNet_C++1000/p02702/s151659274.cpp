#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

const ll MOD = 2019;


int main(){
  string s;cin >> s;
  reverse(s.begin(),s.end());
  ll n = s.size();
  vector<ll> cnt(MOD,0);

  ll x = 1;
  ll total = 0;
  ll ans = 0;
  rep(i,n){
    cnt.at(total)++;
    total += (s.at(i)-'0')*x;
    total %= MOD;
    x = x*10%MOD;
    ans += cnt.at(total);
  }
  cout << ans << endl;
  return 0;
}
