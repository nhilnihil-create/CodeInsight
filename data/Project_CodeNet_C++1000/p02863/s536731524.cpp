#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, T;

vector<pair<int, int>> AB;
int dp[3000 + 10][3000 + 10];

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		AB.push_back(make_pair(a, b));
	}
	
	sort(AB.begin(), AB.end());
	
	int ans = 0;
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= T - 1; j++) {
			dp[i][j] = dp[i - 1][j];
			ans = max(ans, dp[i][j] + AB[i - 1].second);
			if (j - AB[i - 1].first >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - AB[i - 1].first] + AB[i - 1].second);
		}
	}
	cout << ans << endl;
	return 0;
}
