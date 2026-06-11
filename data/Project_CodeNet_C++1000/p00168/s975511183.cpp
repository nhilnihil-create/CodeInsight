#include <iostream>

#include <string.h>

using namespace std;

int main()
{
	int dp[31];

	memset(dp, 0, sizeof(dp));

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i < 31; i++) { dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; }


	const int DATASETS = 1000;

	int n[DATASETS], C = 0;


	while (true)
	{
		cin >> n[C];

		if (n[C] == 0){ goto Exit; }

		C++;
	}

Exit:;

	for (int i = 0; i < C; i++)
	{
		cout << (dp[n[i]] - 1) / 3650 + 1 << endl;
	}

	return 0;
}