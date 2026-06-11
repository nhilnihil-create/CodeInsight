#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
const int NMAX = 2000;

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


int main(){
    com_init();
    int s;
    cin >> s;
    
    ll ans = 0;
    
    for(int i=1; i<=s/3; i++){
        ans += combi(s-2*i-1, i-1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}