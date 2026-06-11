#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC153-E, 1009, 
	int h, n;
	cin >> h >> n;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<ll> dp(2 * 10000 + 1, iINF);
	dp[0] = 0;
	rep(i, 2 * 10000 + 1) {
		rep(j, n) {
			if (0 <= i - a[j]) dp[i] = min(dp[i], dp[i - a[j]] + b[j]);
		}
	}
	ll ans = llINF;
	for (int i = h; i < 2 * 10000 + 1; ++i) {
		ans = min(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}