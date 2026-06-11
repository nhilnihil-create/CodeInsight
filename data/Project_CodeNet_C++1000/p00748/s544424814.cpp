#include <bits/stdc++.h>
#define MAX 1000000
#define INF 1000000000
using namespace std;

int main()
{
	vector<int> dp(MAX, INF), res(MAX, INF), four, odd;
	for (int i = 1; i * (i + 1) * (i + 2) / 6 < MAX; i++) {
		four.push_back(i * (i + 1) * (i + 2) / 6);
		dp[i * (i + 1) * (i + 2) / 6] = 1;
		if (i * (i + 1) * (i + 2) / 6 % 2) {
			odd.push_back(i * (i + 1) * (i + 2) / 6);
			res[i * (i + 1) * (i + 2) / 6] = 1;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = MAX - 1; j >= 0; j--) {
			if (dp[j] != INF) {
				for (int k = 0; k < four.size() && j + four[k] < MAX;k++) {
					dp[j + four[k]] = min(dp[j + four[k]], dp[j] + 1);
				}
			}
		}
	}
	int n;
	while (cin >> n, n) {
		cout << dp[n] << ' ';
		while (res[n] == INF) {
			for (int j = MAX - 1; j >= 0; j--) {
				if (res[j] != INF) {
					for (int k = 0; k < odd.size() && j + odd[k] < MAX; k++) {
						res[j + odd[k]] = min(res[j + odd[k]], res[j] + 1);
					}
				}
			}
		}
		cout << res[n] << endl;
	}
	return 0;
}