#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
const ll MOD = 1e9+7;
ll dp[MAX_N][2];

int main()
{
	string L;
	cin >> L;
	int N = L.size();
	dp[0][0] = 2; dp[0][1] = 1;
	rep(i,N-1)
	{
		if (L[i+1] == '1')
		{
			dp[i+1][0] += dp[i][0] * 2;
			dp[i+1][0] %= MOD;
			dp[i+1][1] += dp[i][1] * 3 + dp[i][0];
			dp[i+1][1] %= MOD;
		}
		else
		{
			dp[i+1][0] += dp[i][0];
			dp[i+1][0] %= MOD;
			dp[i+1][1] += dp[i][1] * 3;
			dp[i+1][1] %= MOD;
		}
	}
	cout << (dp[N-1][0] + dp[N-1][1]) % MOD << endl;
	return 0;
}