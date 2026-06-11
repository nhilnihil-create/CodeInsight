#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, T;

//1-idx
int dp1[3000 + 10][3000 + 10];//dp1[i][j] := [1, i]品目まで食べるかを選んで、jの時間がかかったときのおいしさの最大値 
int dp2[3000 + 10][3000 + 10];//dp2[i][j] := [i, N]品目まで食べるかを選んで、jの時間がかかったときのおいしさの最大値
vector<int> A, B;

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		A.push_back(a), B.push_back(b);
	}
	
	dp1[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= T - 1; j++) {
			dp1[i][j] = dp1[i - 1][j];
			if (j - A[i - 1] >= 0)dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - A[i - 1]] + B[i - 1]);
		}
	}

	dp2[N + 1][0] = 0;
	for (int i = N; i >= 1; i--) {
		for (int j = 0; j <= T - 1; j++) {
			dp2[i][j] = dp2[i + 1][j];
			if (j - A[i - 1] >= 0)dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - A[i - 1]] + B[i - 1]);
		}
	}

	int ans = max(dp1[N][T - 1], dp2[1][T - 1]);
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= T - 1; j++) {
			ans = max(ans, dp1[i][j] + B[i] + dp2[i + 2][T - 1 - j]);
		}
	}
	cout << ans << endl;
	
	return 0;
}
