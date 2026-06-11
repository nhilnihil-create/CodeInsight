#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n, m;
	cin >> n >> m;
	
	vector<int> a(m);
	vector<bool> ok(n, true);
	for(int i = 0; i < m; ++i) {
		cin >> a[i];
		ok[a[i]] = false;
	}
	
	vector<ll> dp(n + 10, 0);
	dp[0] = 1;
	
	for(int i = 0; i < n; ++i) {
		if( ok[i + 1] ) {
			dp[i + 1] += dp[i];
			dp[i + 1] %= MOD_LL;
		}
		
		if( ok[i + 2] ) {
			dp[i + 2] += dp[i];
			dp[i + 2] %= MOD_LL;
		}
	}
	
	cout << dp[n] << endl;
	
	return 0;
}
