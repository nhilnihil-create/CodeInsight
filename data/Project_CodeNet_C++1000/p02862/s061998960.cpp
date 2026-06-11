#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

long long fac[1000010], finv[1000010], inv[1000010];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 1000010; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    ll x,y;
    cin>>x>>y;
    if((2*x-y)%3!=0 || (-x+2*y)%3!=0){
        cout<<0<<endl;
        return 0;
    }

    ll a=(2*x-y)/3,b=(-x+2*y)/3;
    if(a<0 || b<0){
        cout<<0<<endl;
        return 0;
    }

    COMinit();

    cout<<COM(a+b,a)<<endl;
}