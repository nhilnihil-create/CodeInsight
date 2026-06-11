#include<cstdio>
using ull = unsigned long long;
const static unsigned MOD = 1000000007;

ull RepeatSquaring(ull N, ull P){
	if(P == 0 || N == 1) return 1;
	if(!(P & 1)){
		ull t = RepeatSquaring(N, P >> 1);
		return t*t %MOD;
	}
	return N*RepeatSquaring(N, P - 1) % MOD;
}

int main(){
    ull N, K;
    scanf("%llu %llu", &N, &K);
    ull dp[K+1], answer = 0;
    for (ull i = K; i > 0; i--){
        dp[i] = RepeatSquaring(K/i, N);
        for (ull j = i*2; j <= K; j += i){
            dp[i] = (MOD + dp[i] - dp[j]) %MOD;
        }
        answer = (answer + i*dp[i]) %MOD;
    }
    printf("%llu\n", answer);
	return 0;
}