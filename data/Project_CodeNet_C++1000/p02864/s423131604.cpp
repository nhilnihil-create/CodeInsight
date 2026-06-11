#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, K; cin >> N >> K; 
	long long H[310] = {}; 
	for(int i = 1; i <= N; i++) cin >> H[i]; 
	long long dp[310][310][310] = {}; // dp[i列目まで見て][j列変えていて][最後に残したのがk列目]
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			for(int k = 0; k <= N; k++){
				dp[i][j][k] = 1e12; 
			}
		}
	}
	dp[0][0][0] = 0LL; 
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			for(int k = 0; k <= i; k++){
				dp[i+1][j+1][k] = dp[i][j][k]; 
			}
		}
		for(int j = 0; j <= i; j++){
			for(int l = 0; l <= i; l++){
				long long tmp = dp[i][j][l] + max(H[i+1] - H[l], 0LL); 
				dp[i+1][j][i+1] = min(dp[i+1][j][i+1], tmp); 
			}
		}
	}
	long long ans = 1e12; 
	for(int j = 0; j <= K; j++){
		for(int k = 0; k <= N; k++){
			ans = min(ans, dp[N][j][k]); 
		}
	}
	cout << ans << endl; 
}