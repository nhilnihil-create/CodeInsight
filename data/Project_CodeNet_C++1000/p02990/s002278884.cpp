#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';
#define MOD 1000000007

using namespace std;

const int MAX = 5100000;

long long fac[MAX], finv[MAX], inv[MAX];
using namespace std;

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}



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


int main(void){
    ll N, K;
    cin>>N>>K;
    COMinit();
    rep1(i, K){
        ll blue;
        blue=(COM(K-1, i-1));
        blue%=MOD;
        ll red=0;
        if(i==1 && N==K) red++;
        if(N-K>=i-1) red+=COM(N-K-1, i-2);
        red%=MOD;
        if(N-K>=i) red+=COM(N-K-1, i-1)*2;
        red%=MOD;
        if(N-K>=i+1) red+=COM(N-K-1, i);
        red%=MOD;
        cout<<(blue*red)%MOD<<endl;
    }
    return 0;
}
