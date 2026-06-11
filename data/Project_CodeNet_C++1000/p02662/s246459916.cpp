#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, s, a[3000], dp[3001] = { 1 };

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = s; j >= 0; j--) {
			if (j + a[i] <= s)
				dp[j + a[i]] = (dp[j + a[i]] + dp[j]) % mod;
			dp[j] = dp[j] * 2 % mod;
		}
	cout << dp[s] << endl;

}
