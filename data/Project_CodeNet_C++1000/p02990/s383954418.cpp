#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const int inf=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(){
  ll n,k;cin>>n>>k;
  COMinit();
  rep(i,1,k+1){
    ll ans=0;
    ans+=(COM(k-1,i-1)*(2*COM(n-k-1,i-1))%MOD)%MOD;
    ans%=MOD;
    ans+=(COM(k-1,i-1)*(COM(n-k-1,i))%MOD)%MOD;
    ans%=MOD;
    ans+=(COM(k-1,i-1)*(COM(n-k-1,i-2))%MOD)%MOD;
    ans%=MOD;
    if(n-k==0)ans=1;
    if(n-k<i-1)ans=0;
    
    cout<<ans<<endl;
  }
  
}

