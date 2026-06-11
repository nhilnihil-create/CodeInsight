#include<iostream>

typedef long long ll;
ll dp[1001][21];
ll A[1001];

int main(){
	ll n;
	std::cin >> n;
	for (int i = 0; i < n; ++i){
		std::cin >> A[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < n-1; ++i){
		for (int j = 0; j <= 20; ++j){
			if (j + A[i] <= 20){
				dp[i+1][j + A[i]] += dp[i][j];
			}
			if (i && j - A[i] >= 0){
				dp[i+1][j - A[i]] += dp[i][j];
			}
		}
	}
	std::cout << dp[n-1][A[n-1]] << std::endl;
	return 0;
}