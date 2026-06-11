#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

const int MAX = 1e7;
ll fac[MAX], finv[MAX], inv[MAX];

//前処理
void COMinit (){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = mod-inv[mod%i]*(mod/i)%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}
//二項係数
ll COM(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main(){
    int n,k;
    cin >> n >> k;
    int r = n-k;
    int b = k;
    COMinit();
    ll ans = 0;
    for(int i = 1; i <= k; i++){
        ll can = 1;
        can *= COM(n-k+1,i);
        can *= COM(k-1,i-1);
        cout << can%mod << endl;
    }   
}