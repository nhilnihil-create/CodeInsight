#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;

//powをとりつつmodをとる
const ll MOD = 1000000007;

ll mod_pow(ll x,ll n,ll mod){
  if(n==0)return 1;
  ll res=mod_pow(x*x%mod,n/2,mod);
  if(n&1)res=res*x%mod;
  return res;
}
 
int main() {

    ll n;
    cin >> n;

    ll ans = 0;
    ans += mod_pow(10,n,MOD) + mod_pow(8,n,MOD) - (2*mod_pow(9,n,MOD));

    ans = ans%MOD;
    if(ans<0)   ans += MOD;
    cout<<ans<<endl;
    
 return 0;
}
