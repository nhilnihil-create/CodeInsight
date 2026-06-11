#include "bits/stdc++.h"
using namespace std;
const int INF = 1001001001;
int main() {
	int N,M;
	cin >> N >> M; 
	vector<int>A(M);
	vector<int>C(M);
	for (int m = 0;m<M; ++m) {
		int B;
		cin >> A[m] >> B;
		int bit = 0;
		for (int b = 0;b<B;++b) {
			int c;
			cin >> c;
			bit |= 1 << (c-1);
		}
		C[m] = bit;
	}
	/*for (int m = 0; m < M; ++m) {
		cout << C[m]<<  endl;
	}*/
	int nMax = 1 << N;
	vector<vector<int>> dp(M + 1, vector<int>(nMax, INF));	
	dp[0][0] = 0;
	for (int m = 0; m < M; ++m) {
		for (int n = 0; n < nMax; ++n) {
			if (INF != dp[m][n]) {
				dp[m + 1][n] = min(dp[m + 1][n], dp[m][n]);
				int num = n | C[m];
				dp[m + 1][num] = min(dp[m + 1][num], dp[m][n] + A[m]);
			}
		}
		/*for (int n = 0; n < nMax; ++n) {
			cout << dp[m + 1][n] <<  endl;
		}*/
	}

	if (INF == dp[M][nMax - 1]) {
		cout << -1 << endl;
	}
	else{
		cout << dp[M][nMax - 1] << endl;
	}
	return 0;
}