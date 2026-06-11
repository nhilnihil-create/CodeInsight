#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, W;
	cin >> N >> W;
	vector<int> dp(W + 1, 0);
	for (int i = 0, v, w; i < N; i++) {
		cin >> v >> w;
		for (int j = W; j >= w; j--) {
			if (dp[j] < dp[j - w] + v) {
				dp[j] = dp[j - w] + v;
			}
		}
	}
	cout << dp[W] << endl;
	return 0;
}