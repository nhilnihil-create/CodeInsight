#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	cin >> x;
	int dp[100001] = {};
	int kane[6] = {100,101,102,103,104,105};
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j <= x; ++j)
		{
			if ((dp[j] != 0 || j == 0) && j + kane[i] <= x)
			{
				dp[j + kane[i]] = 1;
			}
		}
	}
	cout << dp[x] << endl;
	return 0;
}