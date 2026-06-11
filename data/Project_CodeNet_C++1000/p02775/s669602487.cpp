#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


ll chmin(ll &a, ll b) {
	return a = min(a, b);
}

int main() {
	string s; cin >> s;
	reverse(s.begin(), s.end());
	int n = s.size();
	vector<vector<ll>> dp(n + 2, vector<ll>(2, 1e18));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		ll d = s[i] - '0';
		chmin(dp[i + 1][0], dp[i][0] + d);
		chmin(dp[i + 1][0], dp[i][1] + d + 1);
		chmin(dp[i + 1][1], dp[i][0] + 10 - d);
		chmin(dp[i + 1][1], dp[i][1] + 9 - d);
	}
	cout << min(dp[n][0], dp[n][1] + 1) << endl;
	return 0;
}
