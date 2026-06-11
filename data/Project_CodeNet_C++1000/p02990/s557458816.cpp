#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int NMAX = 2000;
const int MOD = 1000000007;

vector<ll> fac(NMAX+1);
vector<ll> inv(NMAX+1);
vector<ll> fnv(NMAX+1);
vector<ll> power(NMAX+1);

void com_init(){
    
    fac[0]=1LL;
    fac[1]=1LL;
    inv[0]=0LL;
    inv[1]=1LL;
    fnv[0]=1LL;
    fnv[1]=1LL;
    
    for(int i=2; i<NMAX+1; i++){
        fac[i] = fac[i-1]*i % MOD;
        inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
        fnv[i] = fnv[i-1] * inv[i] % MOD;
    }
    return;
}

ll combi(int n, int k){
    if(n<k)return 0LL;
    if(k<0 || n<0 )return 0LL;
    
    return fac[n] * (fnv[k]*fnv[n-k] % MOD) % MOD;
}


int main() {
    int n,k;cin>>n>>k;
    
    com_init();
    
    //i=1
    cout<< n-k+1 << endl;
    
    for(int i=2; i<=k; i++){
        if(i>n-k+1){
            cout << 0 << endl;
            continue;
        }
        
        ll ans = 0;
        
        ans += combi(n-k-1, i-2);
        ans += combi(n-k-1, i-1);
        ans += combi(n-k-1, i-1);
        ans += combi(n-k-1, i);
        
        ans %= MOD;
        
        ans *= combi(k-1, i-1);
        ans %= MOD;
        
        cout << ans << endl;
    }
    
    return 0;
}