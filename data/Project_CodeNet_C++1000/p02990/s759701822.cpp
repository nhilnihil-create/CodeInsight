#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
typedef long long ll;
const ll MOD=1e+9+7;
ll N,K;

//グローバル
template< typename T >
T mod_pow(T x, T n, const T &p) {
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
}

//グローバル
ll n_mod(ll x){
    ll ans=1;
    while(x>0){
        ans*=(x%MOD);
        ans%=MOD;
        x--;
    }
    return ans;
}

int main(){    
    cin >> N >> K;
    //int main
    vector<ll> nCk(K+1),kCi(K+1);;
    vector<ll> ans(K+1);
    nCk[0]=1;
    ll n = N-K+1;
    rep2(i,1,K+1){
        nCk[i]=((nCk[i-1]*((n-i+1)%MOD))%MOD*mod_pow((ll)i,MOD-2,MOD))%MOD;
    }
    n = K-1;
    kCi[0]=1;
    rep2(i,1,K+1){
        kCi[i]=((kCi[i-1]*((n-i+1)%MOD))%MOD*mod_pow((ll)i,MOD-2,MOD))%MOD;
    }


    rep2(i,1,K+1){
        ans[i]=(nCk[i]*kCi[i-1])%MOD;
        cout << ans[i] << endl;
    }

}