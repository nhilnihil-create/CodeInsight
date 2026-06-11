#include<iostream>
#include<queue>
#include<memory>
#include<map>
#include<set>
#include<unordered_map>
#include<array>
#include<vector>
#include<algorithm>
#include<list>
#include<limits>
#include<stdio.h>
#include<math.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using lst = list<int>;

ll dp[301][301][301] = {0};

int main()
{

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			for (int k = 0; k <= N; ++k)
			{
				dp[i][j][k] = 1e18;
			}
		}
	}

	dp[0][0][0] = 0;

	vec H(N+1,0);
	for (int i = 0; i < N; ++i)cin >> H[i+1];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			for (int k = 0; k <= N; ++k)
			{
				// しない
				dp[i + 1][j][i + 1]
					= min(dp[i + 1][j][i + 1], dp[i][j][k] + max(0ll, H[i + 1] - H[k]));

				if (j == K) { continue; }

				// する
				dp[i + 1][j + 1][k]
					= min(dp[i + 1][j + 1][k], dp[i][j][k]);
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			for (int k = 0; k <= N; ++k)
			{
				//printf("(%d,%d,%d) = %ld\n", i, j, k, dp[i][j][k]);
			}
		}
	}


	ll ans = 1e18;
	for (int j = 0; j <= K; ++j)
	{
		for (int k = 0; k <= N; ++k)
		{
			ans = min(ans, dp[N][j][k]);
		}
	}
	cout << ans << endl;

	return 0;
}