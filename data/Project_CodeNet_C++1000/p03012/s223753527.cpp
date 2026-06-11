#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> v(n);
  rep(i,n)
    cin >> v[i];
  
  ll sum = 0;
  rep(i,n)
    sum += v[i];
  
  vector<ll> w(n); w[0] = v[0];
  for(ll i=1; i<n; i++)
    w[i] = w[i-1] + v[i];
  
  ll ans = sum;
  rep(i,n){
    if(ans >= abs(sum - w[i]*2))
      ans = abs(sum - w[i]*2);
  }
  
  cout << ans << endl;
}