#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll ans = 2018; bool fin = false;
  ll L,R; cin >> L >> R;
  for(ll i=L; i<R; i++){
    for(ll j=i+1; j<R+1; j++){
      ll mod = (i*j)%2019;
      if(mod < ans) ans = mod;
      if(ans == 0){ fin = true; break; }
    }
    if(fin) break;
  }
  
  cout << ans << endl;
}