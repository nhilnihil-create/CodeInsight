#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	int r, s, p;
	cin >> r >> s >> p;
	string ss;
	cin >> ss;
	string choose = string(n, '?');
	for (int i = 0; i < n; i++) {
		switch (ss[i]) {
		case 'r':
			choose[i] = 'p';
			break;
		case 's':
			choose[i] = 'r';
			break;
		case 'p':
			choose[i] = 's';
			break;
		}
	}
	vector<int> points(n);
	for (int i = 0; i < n; i++) {
		switch (choose[i]) {
		case 'r':
			points[i] = r;
			break;
		case 's':
			points[i] = s;
			break;
		case 'p':
			points[i] = p;
			break;
		}
	}
	vector<int> dp(n);
	dp[0] = points[0];
	for (int i = 1; i < k; i++) dp[i] = dp[i - 1] + points[i];
	for (int i = k; i < n; i++) {
		if (choose[i] == choose[i - k]) {
			dp[i] = dp[i - 1];
			choose[i] = '?';
		}
		else {
dp[i] += dp[i-1] +points[i];
		}
		
	}
	cout << dp[n - 1];


	return 0;
}