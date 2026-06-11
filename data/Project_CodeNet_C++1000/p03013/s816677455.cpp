#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;


int main() {

	ll N, M;
	cin >> N >> M;

	vector<ll>oks(N + 1, true);

	rep(i, M) {
		ll a;
		cin >> a;
		oks[a] = false;
	}

	vector<ll>dp(N + 1);
	dp[0] = 1;

	rep(i, N) {
		repl(j, i + 1, min(N + 1, i + 3)) {
			if (oks[i]) {
				dp[j] += dp[i];
				dp[j] %= mod;
			}
		}
	}

	cout << dp[N];

	return 0;
}
