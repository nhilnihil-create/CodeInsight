#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n-1);
  rep(i,n-1) cin >> b[i];
  
  a[0] = b[0];
  rep(i,n-2){
    a[i+1] = min(b[i],b[i+1]);
  }
  a[n-1] = b[n-2];
  
  ll ans=0;
  rep(i,n) ans += a[i];
  
  cout << ans << endl;
  return(0);
}