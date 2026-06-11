#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long dp[3030][3030] = { 0 };
int a[3030];
int main() {
	int n;
	int s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			if (a[i] + j <= s) {
				dp[i][a[i] + j] = dp[i][a[i] + j] + dp[i - 1][j] % 998244353;
			}
			dp[i][j] = (dp[i][j] + dp[i - 1][j] * 2) % 998244353;
		}
	}
	cout << dp[n][s] << endl;
	return 0;
}
