#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using product = pair<ll,ll>;
using graph = vector<vector<ll>>;
using vll = vector<ll>;


const int MAX = 3000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

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

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    ll X,Y;
    cin>>X>>Y;
    ll res=0;
    ll n=(2*Y-X)/3;
    ll m=(2*X-Y)/3;
    if((X+Y)%3!=0){
        res=0;
    }else if(n < 0 || m < 0){
        res=0;
    }else{
        COMinit();
        res=COM(n+m,n)%MOD;
    }
    cout<<res;
    return 0;
}