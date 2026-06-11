#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef int_fast64_t ll;

template<int N, typename T, T M>
struct ModFact {
    T fact[N+1];
    T ifact[N+1];
    constexpr ModFact() : fact(), ifact() {
        fact[0] = 1;
        for (int i=0; i<N; ++i)
            fact[i+1] = (fact[i]*(i+1))%M;
        ifact[N] = power(fact[N], M-2);
        for (int i=N-1; i >= 0; --i)
            ifact[i] = (ifact[i+1]*(i+1))%M;
    }
    constexpr T power(T a, T b) {
        T r = 1;
        while (b>0) {
            if((b&1)!=0) r = (r*a)%M;
            a = (a*a)%M;
            b >>= 1;
        }
        return r;
    }
    constexpr T comb(T n, T r) {
        return (((fact[n]*ifact[r])%M)*ifact[n-r])%M;
    }
};
 
ModFact<100000, ll, MOD> fact;

ll N, M, ans = 1;
ll th = 1LL<<45;
ll cnt = 1;
char S[200000];

int main() {
    scanf("%lld\n", &N);
    M = N << 1;
    fread_unlocked(S, 1, M, stdin);
    if(S[0] == 'B' && S[M-1] == 'B') {
        bool f = false;
		size_t i = 0;
        while(i < M-1) {
            if(S[i++] == S[i]) f ^= true;
            if(f) {
                ans *= (cnt << 1) - i;
                if(ans > th) ans %= MOD;
            }
            else if(++cnt > N) break;
        }
        if(cnt != N) ans = 0;
        else ans = ((ans % MOD) * fact.fact[N]) % MOD;
    } else ans = 0;
    printf("%lld\n", ans);
	return 0;
}
