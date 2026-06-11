#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
using namespace std;
#define pie 3.141592653589793238462643383279
#define int long long
#define mod 1000000007
#define INF 1145141919364364
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1) * x % mod;
}
int mod_pow(int x, int y, int mood) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mood;
		}
		x = x * x % mood;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}

int n, m, s[2000], t[2000];
int dp[2010][2010];

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> s[i];
	for (int i = 0; i < m; i++)cin >> t[i];
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)dp[i][0] = 1;
	for (int i = 1; i <= m; i++)dp[0][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			dp[i][j] += mod;
			dp[i][j] %= mod;
		}
	}
	cout << dp[n][m] << endl;
}