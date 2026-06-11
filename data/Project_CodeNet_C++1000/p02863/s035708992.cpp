#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, T;

int dp[3000 + 10][3000 + 10][2];//dp[i][j][k] := i品目まで食べるかを選んで、jの時間がかかったときのおいしさの最大値 
//kが0の時は、最後に食べるものをまだ選んでない 1の時は最後に食べるものをもう選んでる状態
vector<int> A, B;

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		A.push_back(a), B.push_back(b);
	}
	
	dp[0][0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= T - 1; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				if (j - A[i - 1] >= 0)
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - A[i - 1]][k] + B[i - 1]);
				//最後に食べるとする
				if (k == 0) {
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][k] + B[i - 1]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= T - 1; i++)for (int j = 0; j < 2; j++)
		ans = max(ans, dp[N][i][j]);
	cout << ans << endl;
	return 0;
}
