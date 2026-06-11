#include <iostream>
#include <cstring>
using namespace std;

const int mxN = 1e4 + 5;
int dp[mxN], a[mxN], b[mxN];

int main() {
	int h, n;
	cin >> h >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];
	memset(dp, 0x3F, sizeof dp);
	dp[0] = 0;
	for(int i = 1; i <= h; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(a[j] > i)
				dp[i] = min(dp[i], b[j]);
			else
				dp[i] = min(b[j] + dp[i - a[j]], dp[i]);
		}
	}
	cout << dp[h];
}
