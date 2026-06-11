#include <cstdio>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <cstdlib>
#include <queue>
#include <iomanip>
// #include <unordered_map>
#define P pair<int, int>
#define LL long long
#define LD long double
#define PLL pair<LL, LL>
#define mset(a, b) memset(a, b, sizeof(a))
#define rep(i, a, b) for (int i = a; i < b; i++)
#define PI acos(-1.0)
#define random(x) rand() % x
#define debug(x) cout << #x << " " << x << "\n"
using namespace std;
const int inf = 0x3f3f3f3f;
const LL __64inf = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
const int MAX = 1e6 + 50;
#else
const int MAX = 1e6 + 50;
#endif
const int mod = 1e9 + 7;

LL N,K;
LL f[MAX];
LL fact[MAX];
inline LL add(LL x, LL y){
    LL res = x + y;
    return res >= mod ? res - mod : res;
}
inline LL qpow(LL x, LL n){
    LL res = 1;
    while (n)
    {
        if(n &1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
LL F(LL K, LL N){
    if(f[K]) return f[K];
    LL &res =f[K];
    if(K==1){
        return res = 1;
    }
    // res = qpow(K, N);
    res = fact[K];
    for(LL i = 2, j; i <= K; i=j+1){
        j = K/(K/i);
        // res = add(res, mod-F(K/i, N));
        LL tmp = (j-i+1LL) * F(K/i, N) % mod;
        res = add(res, mod-tmp);                                                                    
    }
    return res;
}
int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    scanf("%lld%lld", &N, &K);
    for(LL i = 1; i <= K; i++)
        fact[i] = qpow(i, N);
    LL ans = 0;
    f[1] = 1LL;
    for(LL k= 1; k <= K; k++){
        F(k, N);
        // LL &res = f[k];
        // res = qpow(k, N);
        // for(LL i = 2, j; i <= k; i=j+1){
        //      j = k/(k/i);
        //     res = add(res, mod-f[k/i]);
        //     LL tmp = (j-i+1LL) * f[k/i] % mod;
        //     res = add(res, mod-tmp);      
        // }
    }
    for(LL i = 1, j; i <= K; i++){
        // j = K/(K/i);
        // ans +=  F(K/i, N) % mod * i % mod;
        ans +=  f[K/i] % mod * i % mod;
        if(ans >= mod)
            ans -= mod;
    }
    printf("%lld\n", ans);
}
