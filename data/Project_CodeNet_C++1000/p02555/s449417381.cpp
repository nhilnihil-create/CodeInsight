#include <iostream>

using namespace std;

long long int MOD = 1000000007;

long long int dp[2020][2020];

int S;

long long int C[2020][2020];

int main(void) {

	cin >> S;

	/*dp[0][0] = 1;
	for (int i = 1; i <= S/3+1; i++) {
		for(int j=0;j<=S;j++){
			for (int k = 3; k <= S; k++) {
				if (j + k > S) { break; }
				dp[i][j + k] += dp[i - 1][j];
				dp[i][j + k] %= MOD;
		  }
		}
	}

	long long int ans = 0;
	for (int i = 1; i <= S; i++) {
		ans += dp[i][S];
		ans %= MOD;
	}

	cout << ans << endl;*/

	C[0][0] = 1;

	for (int i = 1; i <= S; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for (int i = 1; i <= S; i++) {
		for (int j = 1; j <= i - 1; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}

	/*for (int i = 1; i <= 4; i++) {
		for (int j = 0; j <= i; j++) {
			cout << "C[" << i << "][" << j << "]= " << C[i][j] << endl;
		}
	}*/

	long long int ans = 0;

	for (int i = 1; i <= S / 3; i++) {
		ans += C[S - 3 * i + i - 1][i - 1];
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}