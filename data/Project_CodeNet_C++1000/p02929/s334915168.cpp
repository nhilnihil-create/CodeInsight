#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef int_fast64_t ll;

template<int N, typename T, T M>
struct ModFact {
    T fact[N+1];
    constexpr ModFact() : fact() {
        fact[0] = 1;
        for (int i=0; i<N; ++i)
            fact[i+1] = (fact[i]*(i+1))%M;
    }
};
 
ModFact<100000, ll, MOD> fact;

ll ans;
int N, M, cnt = 0;
constexpr ll th = 1LL<<45;
char S[200000];

int main() {
    scanf("%d\n", &N);
    M = N << 1;
    fread_unlocked(S, 1, M, stdin);
    ans = fact.fact[N];
	for(size_t i = 0; i < M;) {
		if((S[i++]^cnt)&1) {
            ans *= cnt;
            if(ans > th) ans %= MOD;
            if(--cnt < 0) break;
        } else ++cnt;
	}
    printf("%lld\n", cnt == 0 ? ans % MOD : 0);
    return 0;
}
