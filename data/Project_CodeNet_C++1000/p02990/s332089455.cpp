#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;

//二項係数
const int MAX = 3000;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
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
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    ll N,K;
    cin>>N>>K;
    COMinit();
    if(N==K){
        cout<<1<<endl;
        rep(i,K-1)cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=K;i++){
        ll ans=0;
        ans+=COM(N-K-1,i)*COM(K-1,i-1)%MOD;
        ans+=COM(N-K-1,i-1)*COM(K-1,i-1)%MOD;
        ans%=MOD;
        ans+=COM(N-K-1,i-1)*COM(K-1,i-1)%MOD;
        ans%=MOD;
        if(i>=2)ans+=COM(N-K-1,i-2)*COM(K-1,i-1)%MOD;
        ans%=MOD;
        cout<<ans<<endl;
    }
}