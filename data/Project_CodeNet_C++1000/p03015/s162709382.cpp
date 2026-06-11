#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, i, li;
	ll dp[100003][2] = {};
	string l;

	cin >> l;

	n = l.size();

	dp[0][0] = 1;
	dp[0][1] = 0;
	for (i = 0; i < n; i++) {
		li = l[i] - '0';
		dp[i + 1][0] = dp[i][0] * (li + 1) % mod;
		dp[i + 1][1] = (dp[i][0] * li + dp[i][1] * 3 % mod) % mod;
	}

	printf("%lld\n", (dp[n][0] + dp[n][1]) % mod);

	return 0;
}