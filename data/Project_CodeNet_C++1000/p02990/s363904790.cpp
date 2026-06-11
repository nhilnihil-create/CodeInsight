#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>

using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=1001001000;
const ll LLMAX=1010010010010010000;

vll fac, finv, inv;

void COMinit(ll MAX) {
    if(MAX<1) return;
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    if(k==0 || n==k) return 1;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll modmul(ll a,ll b,ll mod=MOD){
    return ((a%mod)*(b%mod))%mod;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N,K;
    cin>>N>>K;
    
    COMinit(max(K,N-K+2));
    
    for(int i=1;i<=K;i++)
        cout<<modmul(COM(K-1,i-1),COM(N-K+1,i))<<endl;
    
    return 0;
}
