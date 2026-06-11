#include<cstdio>
using ull = unsigned long long;
const static ull MOD = 1000000007;

int main(){
	ull N;
	scanf("%llu", &N);
	ull n_1[60];
	for (int i = 0; i < 60; ++i){
		n_1[i] = 0;
	}
	for (int i = 0; i < N; ++i){
		ull a;
		scanf("%llu", &a);
		for (unsigned j = 0; j < 60; ++j){
			if(a & (1ULL << j)) n_1[j]++;
		}
	}
	ull ans = 0;
	for (unsigned i = 0; i < 60; ++i){
		ans = (ans + n_1[i]*(N - n_1[i])%MOD*((1ULL << i)%MOD))%MOD;
	}
	printf("%llu\n", ans);
	return 0;
}