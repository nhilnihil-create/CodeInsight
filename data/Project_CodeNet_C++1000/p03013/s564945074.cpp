#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<int> a(m); 
	for (int i = 0; i < m; i++)
		cin >> a[i];

	vector<int> dp(n+1, -1);
	for (int i = 0; i < m; i++)
		dp[a[i]] = 0;

	if(dp[0]!=0)
		dp[0] = 1; 
	if(dp[1]!=0)
		dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (dp[i] != 0) {
			dp[i] = dp[i - 1] + dp[i - 2];
			if (dp[i] > 1000000007)
				dp[i] %= 1000000007;
		}
	}

	cout << dp[n] << endl;
}