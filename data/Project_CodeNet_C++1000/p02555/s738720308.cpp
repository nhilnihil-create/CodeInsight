#include <iostream>
#include <math.h>
#include <algorithm>
#define ll long long
#define DIV 1000000007

using namespace std;

int s;
ll dp[2001], p[2001];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> s;
	dp[3] = 1, p[3] = 1;
	dp[4] = 1, p[4] = 2;
	dp[5] = 1, p[5] = 3;

	for (int i = 6; i <= s; i++) {
		dp[i] = p[i - 3] - p[2] + 1 + DIV;
		dp[i] %= DIV;
		p[i] = p[i - 1] + dp[i];
		p[i] %= DIV;
	}
	cout << dp[s];
	return 0;
}