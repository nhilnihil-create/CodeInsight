#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
ll dp[10][20];//dp[i][j]代表以i开头的j位数有多少个lunlun 
ll sum[20], pos;
ll k;
void dfs(ll num, ll lst) {
	if (num > pos) return;
	if (num == 1) {
		for (ll i = 1; i < 10; i++) {
			if (k > dp[i][pos - num + 1]) {
				k -= dp[i][pos - num + 1];
			} else {
				putchar(i + '0');
				dfs(num + 1, i);
				break;
			}
		}
	} else {
		for (ll i = lst - 1; i <= lst + 1; i++) {
			if (i < 0 || i > 9) continue;//记住特判 
			if (k > dp[i][pos - num + 1]) {
				k -= dp[i][pos - num + 1];
			} else {
				putchar(i + '0');
				dfs(num + 1, i);
				break;
			}
		}
	}
}
int main() {
	cin >> k;
	for (ll i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}
	sum[1] = 9;
	for (ll j = 2; j <= 10; j++) {
		for (ll i = 0; i < 10; i++) {
			if (i != 0 && i != 9) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + dp[i + 1][j - 1];
			else if (i != 0) dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			else if (i != 9) dp[i][j] = dp[i][j - 1] + dp[i + 1][j - 1];
			if (i != 0) sum[j] += dp[i][j];
		}
	}
	for (ll i = 1; i <= 20; i++) {
		if (k > sum[i]) {
			k -= sum[i];
		} else {
			pos = i;
			break;
		}
	}
	dfs(1, 0);
	return 0;
}