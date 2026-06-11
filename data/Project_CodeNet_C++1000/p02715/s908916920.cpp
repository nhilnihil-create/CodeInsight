#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, K;
ll num[100001];
map<ll, ll> powN;

long long modpow(long long x, long long n, long long MOD){
    long long ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n = (n >> 1);
    }
    return ret;
}


signed main(){
    cin >> N >> K;
    ll ans = 0;
    for(ll i = K; i >= 1; i--){
        num[i] = modpow(K / i, N, MOD);
        for(ll j = 2; i * j <= K; j++) num[i] = (num[i] + MOD - num[i * j]) % MOD;
        ans = (ans + i * num[i] % MOD) % MOD;
    }
    PRINT(ans);
    return 0;
}