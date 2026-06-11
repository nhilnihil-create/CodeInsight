#include <iostream>
#include <vector>
#include<queue>
using namespace std;
#define loop(i,n) for (int i = 0; i < n; i++)
#define loops(i,f,n) for (int i = (f); i < n; i++)

bool check(int x)
{
	return (0 <= x&&x <= 20);
}

int main()
{
	int n;
	cin >> n;
	vector<int> num(n);
	loop(i, n)cin >> num[i];
	long long int dp[100][21] = { 0 };
	dp[0][num[0]] = 1;
	loops(i, 1, n-1)
	{
		loop(j, 21)
		{
			if (dp[i - 1][j] != 0 && check(j + num[i]))dp[i][j + num[i]] += dp[i - 1][j];
			if (dp[i - 1][j] != 0 && check(j - num[i]))dp[i][j - num[i]] += dp[i - 1][j];
		}
	}

	cout << dp[n - 2][num[n - 1]] << endl;
	return 0;
}