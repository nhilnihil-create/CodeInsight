#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  map<string, ll> mp;
  rep(i, n){
    string S;  cin >> S;
    sort(S.begin(),S.end());
    mp[S]++;
  }
  
  ll ans = 0;
  for(auto it = mp.begin(); it != mp.end(); it++){
    ll t = it -> second;
    ans += (t*(t-1)) / 2;
  }
  
  cout << ans << endl;
}