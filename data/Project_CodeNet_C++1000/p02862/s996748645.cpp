#include <bits/stdc++.h>

typedef long long ll;
#define ALL(l)  (l).begin(),(l).end()
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pb push_back
using namespace std;

const ll mod =  1000000007;
//const ll maxn = 1000000000;

//---------------------------------------------------------------------------------------------------
using vi = vector<int>; // intの1次元の型に vi という別名をつける
using vll = vector<ll>; // intの1次元の型に vi という別名をつける
using vvll = vector<vll>; // intの2次元の型に vvi という別名をつける
using vs = vector<string>; // stringの1次元の型に vs という別名をつける
using pll = pair<ll, ll>; // これ以降 pii という型名はpair<ll, ll> と同じ意味で使える
//---------------------------------------------------------------------------------------------------

const int MAX = 5100000;
const int MOD = 1000000007;

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
    COMinit();
    
    ll x,y,ans=0,s,t;
    cin>>x>>y;
    if((x+y)%3==0&&(2*y-x)>=0&&(2*y-x)%3==0){
        s=(x+y)/3;
        t=(2*y-x)/3;
        ans=COM(s,t);
    }

    cout<<ans<<endl;
}
