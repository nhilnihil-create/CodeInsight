#include<cstdio>
using ll = long long;
using ull = unsigned long long;
const static int MOD = 1000000007;

ll RepeatSquaring(ll N, ull P){
	if(P == 0 || N == 1) return 1;
	if(N == -1) return P & 1 ? -1 : 1;
	if(!(P & 1)){
		ll t = RepeatSquaring(N, P >> 1);
		return t*t % MOD;
	}
	return N*RepeatSquaring(N, P - 1) % MOD;
}

ull Combination(ull n, ull r){
	ull ret = 1;
	if(n - r < r) r = n - r;
	ull denominator = 1;
	for (ull i = 0; i < r; ++i){
		ret = ret*((n - i) %MOD) %MOD;
		denominator = denominator*((i + 1) %MOD) %MOD;
	}
	return ret*RepeatSquaring(denominator, MOD-2) %MOD;
}
int main(){
	ull X, Y;
	scanf("%llu %llu", &X, &Y);
	ull sum = X + Y;
	if(sum % 3){
		printf("0\n");
		return 0;
	}
	ull moves = sum/3;
	if(X < moves || Y < moves){
		printf("0\n");
	}else{
		printf("%llu\n", Combination(moves, X - moves));
	}
	return 0;
}