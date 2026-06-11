#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int P(int a, int b) {
	if(b == 0) return 1;
	if(b & 1) return (long long)P(a, b - 1) * a % mod;
	int t = P(a, b / 2);
	return (long long)t * t % mod;
}

const int O = P(2, mod - 2);

int H(int a) {
	return (long long)a * O % mod;
}

const int S = 3003;
int n, s, x, dp[S];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s; dp[0] = P(2, n);
	for(int i = 1; i <= n; ++i) {
		cin >> x;
		for(int i = s; i >= x; --i) {
			(dp[i] += H(dp[i - x])) %= mod;
		}
	}
	cout << dp[s] << endl;
	return 0;
}
