#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;
const ll mod = 1e9 + 7;
 
int main(){
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for(ll i=0; i <= n-k+1; i++){
    ll s = (i*(n-i+1)+1)%mod;
    ans = (ans + s) %mod;
  }
  cout << ans << endl; 
  
  return 0;
}
