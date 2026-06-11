#include <iostream>
using namespace std;
int main()
{
	int n = 0; unsigned long long  z = 0; int k = 0; int p = 0;
	unsigned long long dp[21][105] = { 0 };
	cin >> n;
	cin >> k;
		dp[k][0] = 1;
	for (int i = 1; i < n-1; i++) {
		cin >> p;
		for (int j = 0; j < 21; j++) {
			if (j - p >= 0)dp[j][i] += dp[j - p][i - 1];
			if (j + p<= 20)dp[j][i]+= dp[j + p][i - 1];
		}
	}
	cin >> p;
	cout << dp[p][n-2] << endl;

    return 0;
}
