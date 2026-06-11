#include <bits/stdc++.h>
using namespace std;

int n;
long long num[2005], loc[2005];
long long dp[2005][2005] = {0};

struct node {
	long long a, id;
}	input[2005];

bool comp (node xx, node yy) {
	return xx.a > yy.a;
}

int main () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> input[i].a;
		input[i].id = (long long)(i);
	}
	sort (input+1, input+n+1, comp);
	for (int i = 1; i <= n; ++i) {
		num[i] = input[i].a;
		loc[i] = input[i].id;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= i; ++j) {
			if (j == 0) {
				dp[j][i-j] = dp[j][i-j-1] + num[i] * abs (loc[i] - (n-(i-j)+1));
				continue;
			}
			if (i-j == 0) {
				dp[j][i-j] = dp[j-1][i-j] + num[i] * abs (loc[i] - j);
				continue;
			}
			dp[j][i-j] = max (dp[j-1][i-j] + num[i] * abs (loc[i] - j), dp[j][i-j-1] + num[i] * abs (loc[i] - (n-(i-j)+1)));
		}
	long long mx = -1;
	for (int i = 0; i <= n; ++i)
		mx = max (mx, dp[i][n-i]);
	cout << mx << endl;
	return 0;
}