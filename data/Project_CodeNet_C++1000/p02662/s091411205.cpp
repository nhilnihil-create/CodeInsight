#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
	int MOD = 998244353;
	int N, S;
	cin >> N >> S;
	int A[N];
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A,A+N);
	if (A[0] > S) {
		cout << 0 << endl;
		return 0;
	}

	int dp[N+1][S+1];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			dp[i][j] = 0;
		}
	}
	
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= S; j++) {
			dp[i+1][j] += 2*dp[i][j];
			dp[i+1][j] %= MOD;
			if (A[i] <= j){ 
				dp[i+1][j] += dp[i][j-A[i]];
				dp[i+1][j] %= MOD;	
			}
		}
	}
		cout <<  dp[N][S] << endl;

return 0;
}
