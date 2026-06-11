#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=1e9+7;

const int MAX = 1000000+5;

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


ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    ll X, Y; cin >> X >> Y;
    ll res=0;
    COMinit();
    for(int i=0; i<=X/2; i++){
        if((Y-i)%2 != 0) continue;
        if((Y-i)/2+2*i != X) continue;
        res=(res+COM(Y-(Y-i)/2, i))%MOD;
    }
    cout << res << endl;
    return 0;
}