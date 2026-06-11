#include <iostream>
#include <vector>
using namespace std;
long long INF = 1000000000000000;
int main(){
	int N, K;
	cin >> N >> K;
	vector<int> H(N);
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
	if (N == K){
		cout << 0 << endl;
	} else {
		vector<vector<long long>> dp(N - K, vector<long long>(N, INF));
		for (int i = 0; i < N; i++){
			for (int j = N - K - 2; j >= 0; j--){
				for (int k = 0; k < i; k++){
					dp[j + 1][i] = min(dp[j + 1][i], dp[j][k] + abs(H[i] - H[k]));
				}
			}
			dp[0][i] = H[i];
		}
		long long ans = INF;
		for (int i = 0; i < N; i++){
			ans = min(ans, (dp[N - K - 1][i] + H[i]) / 2);
		}
		cout << ans << endl;
	}
}