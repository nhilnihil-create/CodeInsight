#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<stack>
#include<set>
#include<map>

using ll = long long;

using namespace std;

long long x = 1000000007;

ll n_pow(ll a, ll n) {
	if (n == 0)return 1;
	ll t = n_pow(a, n / 2);
	t *= t;
	t %= x;
	if (n % 2 == 1)t *= a;
	return t % x;
}

const int INF = 1001001001;

int main() {
	string n;
	cin >> n;
	ll ans = 0;
	int k = 0;
	reverse(n.begin(), n.end());
	n += '0';
	vector<vector<int>>dp(n.size() + 1, vector<int>(2));
	for (int i = 0; i < n.size() + 1; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n.size(); i++) {
		for (int j = 0; j < 2; j++) {
			int c = n[i] - '0';
			c += j;
			if (c < 10) {
				dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + c);
			}
			if (c > 0) {
				dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + (10 - c));
			}
		}
	}
	cout << dp[n.size()][0] << endl;
	return 0;
}