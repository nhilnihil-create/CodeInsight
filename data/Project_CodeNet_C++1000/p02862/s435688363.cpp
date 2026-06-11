#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const int MAX = 2000007;
const int MOD = 1000000007;

ll fac[MAX],finv[MAX],inv[MAX];

void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2; i<MAX;++i){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll COM(int n, int k){
    if(n < k)return 0;
    if(n < 0 || k < 0)return 0;
    return fac[n] * (finv[k] * finv[n-k] %MOD)%MOD;
}

int main() {
    COMinit();
    
    int x,y; cin>>x>>y;
    int ans = 0;
    if( (x + y)%3 != 0)ans = 0;
    else{
        int n = (x + y)/3;
        int k = (n - abs(x - y))/2;
        ans = COM(n, k);
    }
    
    cout<<ans<<endl;
	return 0;
}