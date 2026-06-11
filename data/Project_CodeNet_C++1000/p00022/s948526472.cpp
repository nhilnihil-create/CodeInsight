#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MIN (-(1<<20))
vector<int> dp(5001);
vector<int> v(5001);
int main()
{
	int n;
	while (true) {
		cin >> n;
		if (n == 0) break;
		fill(dp.begin(), dp.end(), MIN);
		for (int i = 0; i < n; ++i) cin >> v[i];
		dp[0] = v[0];
		for (int i = 1; i < n; ++i)
			dp[i] = max(v[i], dp[i-1] + v[i]);
		sort(dp.begin(), dp.begin() + n);
		cout << dp[n-1] << endl;
	}
	return 0;
}