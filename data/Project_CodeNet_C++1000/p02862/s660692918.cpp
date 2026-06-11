#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// nCr mod を計算する O(n)
const int MAX_N = 1000010;
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX_N; i++){
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
    COMinit();

    if((2*y-x)%3!=0 || (2*x-y)%3!=0){
        cout<<0<<endl;
        return 0;
    }

    ll a=(2*y-x)/3;
    ll b=(2*x-y)/3;

    cout<<COM(a+b,a)<<endl;
}

 