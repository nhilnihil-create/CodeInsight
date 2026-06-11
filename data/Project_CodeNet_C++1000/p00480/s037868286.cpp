#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(false);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];

	vector<vector<long long> > dp(n, vector<long long>(21, 0));
	dp[0][a[0]] = 1;

	for(int i = 0; i < n - 2; ++i) {
		for(int j = 0; j <= 20; ++j) {
			if(j + a[i + 1] <= 20)
				dp[i + 1][j + a[i + 1]] += dp[i][j];

			if(0 <= j - a[i + 1])
				dp[i + 1][j - a[i + 1]] += dp[i][j];
		}
	}

	cout << dp[n - 2][a[n - 1]] << endl;

	return EXIT_SUCCESS;
}