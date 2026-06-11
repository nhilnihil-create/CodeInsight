#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v.at(i);
  ll ans = 0;
  
  ll cnt = 0;
  rep(i, n-1){
    if(v.at(i) >= v.at(i+1))  cnt++;
    else  cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}