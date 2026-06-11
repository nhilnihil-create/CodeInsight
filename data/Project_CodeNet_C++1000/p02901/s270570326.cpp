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
int dp[5000][1100];
int a[1100];
int b;
int c[1100];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < 1100; j++) {
			dp[i][j] = 1000000007;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b;
		bitset<13> bit;
		for (int j = 0; j < b; j++) {
			int d;
			cin >> d;
			d--;
			bit[d] = 1;
		}
		c[i] = bit.to_ulong();
	}
	dp[0][0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (1 << n); j++) {
			dp[(j | c[i])][i] = min(dp[(j | c[i])][i], dp[j][i - 1] + a[i]);
			dp[j][i] = min(dp[j][i], dp[j][i - 1]);
		}
	}
	if (dp[(1 << n) - 1][m] == 1000000007) {
		cout << "-1" << endl;
		return 0;
	}
	cout << dp[(1 << n) - 1][m] << endl;
}