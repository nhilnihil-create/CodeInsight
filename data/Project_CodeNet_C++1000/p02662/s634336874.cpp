#include<bits/stdc++.h>
using namespace std;

#define DIV 998244353

long long N, S;
long long A[3005];
long long dp[3005][3005];

long long modpow(long long ori, long long po){
	long long res = 1;
	while(po > 0){
		if(po&1){
			res *= ori;
			res %= DIV;
		}
		ori *= ori;
		ori %= DIV;
		po >>= 1;
	}
	return res;
}

int main(){
	cin >> N >> S;
	for(long long i = 0; i < N; i++) {
		cin >> A[i];
	}

	dp[0][0] = modpow(2, N);
	for(long long i = 0; i < N; i++) {
		for(long long j = 0; j < 3005; j++) {
			//そのまま
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= DIV;

			//A[i]を使う
			if(j + A[i] <= S) {
				dp[i+1][j+A[i]] += dp[i][j] * modpow(2, DIV-2);
				dp[i+1][j+A[i]] %= DIV;
			}
		}
	}
	cout << dp[N][S] << endl;

}

