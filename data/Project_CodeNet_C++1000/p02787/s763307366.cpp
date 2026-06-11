#include <bits/stdc++.h>

using namespace std;


int main()
{
	uint64_t H, N, A, B;
	cin >> H >> N;
	vector<uint64_t> dp(H + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> A >> B;
		for (int j = 0; j <= H; ++j)
			if (dp[j] != INT_MAX)
				dp[min(j + A, H)] = min(dp[min(j + A, H)], dp[j] + B);
	}
	cout << dp[H];
	return 0;
}
