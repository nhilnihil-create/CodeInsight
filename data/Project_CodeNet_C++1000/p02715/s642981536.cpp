#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <ctime>
#include <numeric>
using namespace std;

#define pb push_back
#define pii pair <int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(x) (x).resize(unique(all(x)) - (x).begin())
#define ld long double
#define int long long
const int mod = 1e9 + 7;

int bpow(int a, int n) {
	int ret = 1;
	while (n) {
		if (n & 1)
			(ret *= a) %= mod;
		(a *= a) %= mod;
		n /= 2;
	}
	return ret;
}

int dp[100500];

void SOLVE() {
	int n, k;
	cin >> n >> k;

	int ans = 0;
	for (int g = k; g >= 1; g--) {
		int cur = bpow(k / g, n);
		for (int i = 2 * g; i <= k; i += g) {
			cur = (cur - dp[i] + mod) % mod;
		}
		dp[g] = cur;
		(ans += cur * g % mod) %= mod;
	}

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << fixed;
	cout.precision(10);
	int Q = 1;
	//cin >> Q;
	while (Q--) {
		SOLVE();
	}

	return 0;
}