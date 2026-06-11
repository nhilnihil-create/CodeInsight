#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, t;
	cin >> n >> t;
	vector<int> a(n), b(n);
	vector<int> arev(n), brev(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	for (int i = 0; i < n; i++) {
		arev[i] = a[n-1-i];
		brev[i] = b[n-1-i];
	}

	long long dp1[n-1][t]; // 0 ~ n-2
	long long dp2[n-1][t]; // n-1 ~ 1
	for (int j = 0; j < t; j++) {
		if (j < a[0])
			dp1[0][j] = 0;
		else
			dp1[0][j] = b[0];
	}
	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j < t; j++) {
			if (j-a[i] < 0) {
				dp1[i][j] = dp1[i-1][j];
				continue;
			}
			dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j-a[i]]+b[i]);
		}
	}

	for (int j = 0; j < t; j++) {
		if (j < arev[0])
			dp2[0][j] = 0;
		else
			dp2[0][j] = brev[0];
	}
	for (int i = 1; i < n-1; i++) {
		for (int j = 0; j < t; j++) {
			if (j-arev[i] < 0) {
				dp2[i][j] = dp2[i-1][j];
				continue;
			}
			dp2[i][j] = max(dp2[i-1][j], dp2[i-1][j-arev[i]]+brev[i]);
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long max = 0;
		for (int j = 0; j < t; j++) {
			long long tmp = 0;
			if ((i-1) >= 0)
				tmp += dp1[i-1][j];
			if ((n-2-i) >= 0 && (t-1-j)>=0)
				tmp += dp2[n-2-i][t-1-j];
			tmp += b[i];

			if (tmp > max)
				max = tmp;
		}
		if (ans < max)
			ans = max;
	}
	cout << ans << endl;

	return 0;
}