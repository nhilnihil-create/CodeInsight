#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long int MOD = 998244353;

int N, S, A[3333];

long long int dp[3030][6030];


int main(void) {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	//cout << "check" << endl;

	dp[0][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 3000; j++) {
			dp[i][j] += dp[i - 1][j]*2; dp[i][j] %= MOD;
			dp[i][j + A[i]] += dp[i - 1][j]; dp[i][j + A[i]] %= MOD;
		}
	}

	/*for (int j = 0; j <= 10; j++) {
		cout << "dp[" << N << "][" << j << "]= " << dp[N][j] << endl;
	}*/


	long long int ans = dp[N][S];



	cout << ans << endl;

	return 0;
}