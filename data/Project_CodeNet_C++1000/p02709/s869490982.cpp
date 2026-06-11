#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;




int main() {
	int n;
	cin >> n;
	vector<pll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end(), greater<pll>());

	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1,-INF));
	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int l = i - j;
			int r = j;

			dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + a[i].first * (a[i].second - l));
			dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + a[i].first * ((n - r - 1) - a[i].second));

		}
	}

	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		int l = n - i;
		int r = i;

		ans = max(ans, dp[l][r]);

	}

	cout << ans << endl;

}
