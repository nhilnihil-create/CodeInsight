#include <iostream>

using namespace std;

const long long MOD = 998244353;

long long modpow(long long c, long long n){
	long long ret = 1;
	while(n != 0){
		if(n&1){
			ret = ret * c % MOD;
		}
		c = c * c % MOD;
		n /= 2;
	}
	return ret;
}

int main(){
	int N, S;
	cin >> N >> S;
	int A[N];
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}

	long long dp[N][S + 1];

	for (int i = 0; i < N; i++){
		for (int j = 0; j <= S; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 2;
	dp[0][A[0]] = 1;

	for (int i = 1; i < N; i++){
		for (int j = 0; j <= S; j++){
			dp[i][j] = 2 * dp[i - 1][j] % MOD;
			if(j - A[i] >= 0){
				dp[i][j] += dp[i - 1][j - A[i]];
			}
			dp[i][j] %= MOD;
		}
	}

		cout << dp[N - 1][S] << endl;
	return 0;
}
