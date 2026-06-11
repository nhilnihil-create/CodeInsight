#include<cstdio>
#include<string>
#include<iostream>
using ll = long long;
using ull = unsigned long long;
const static unsigned MOD = 1000000007;
ull dp[2][13];

ll RepeatSquaring(ll N, ull P, ull mod){
	if(P == 0 || N == 1) return 1;
	if(N == -1) return P & 1 ? -1 : 1;
	if(!(P & 1)){
		ll t = RepeatSquaring(N, P >> 1, mod);
		return t*t %mod;
	}
	return N*RepeatSquaring(N, P - 1, mod) % mod;
}

int main(){
    std::string S;
    std::cin >> S;
    unsigned even = 0, sz = S.size(), ten = RepeatSquaring(10, sz-1, 13), decided = 0;
    dp[0][0] = 1;
    for (size_t i = 0; i < sz; i++){
        if(S[i] != '?') decided = (decided + (S[i] - '0')*ten) %13;
        else{
            even ^= 1;
            for (size_t remainder = 0; remainder < 13; remainder++) dp[even][remainder] = 0;
            for (size_t digit = 0; digit <= 9; digit++){
                for (size_t remainder = 0; remainder < 13; remainder++){
                    (dp[even][(remainder + digit*ten) % 13] += dp[even^1][remainder]) %= MOD;
                }
            }
        }
        ten = ten*4 %13;
    }
    printf("%llu\n", dp[even][(18 - decided) %13]);
	return 0;
}