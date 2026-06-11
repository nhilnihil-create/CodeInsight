#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int modpow(ll a, ll n, ll p){
  if(n==0) return 1;
  if(n==1) return a%p;
  if(n%2 == 1) return (a*modpow(a,n-1,p))%p;
  ll t = modpow(a,n/2, p);
  return (t*t)%p;
 }

ll modnCa(ll n, ll a, ll p){
  ll upper = 1;
  ll lower = 1;
  for(ll i = 1; i <= a; i++){
    upper *= n-i+1;
    upper %= p;
    lower *= i;
    lower %= p;
  }
  ll inv_lower = modpow(lower, p-2, p);
  return (upper * inv_lower)%p;
}


int main(){
  ll n, k;
  cin >> n >> k;
  ll mod = 1000000007;

  for(ll i = 1; i<k+1; i++){
    ll ans = modnCa(n-k+1,i,mod)*modnCa(k-1,i-1,mod);
    ans %= mod;
    cout << ans  << endl;
  }
  
  
}
