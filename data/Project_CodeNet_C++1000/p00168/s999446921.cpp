#include <iostream>

using namespace std;
int dp[32];

void solve()
{
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for(int i = 3; i < 30; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	int n;
	while(cin >> n, n)
	{
		cout << dp[n - 1] / 3650 + 1 << endl;
	}
}

int main()
{
	solve();
	return(0);
}