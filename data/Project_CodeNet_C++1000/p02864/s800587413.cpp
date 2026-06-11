#include <bits/stdc++.h>

using namespace std;

int n;

const int N = 300;
const int K = N;
const int H = 1e9;
const long long LLINF = N * 1LL * H + 7;

long long dp[N + 7][K + 7];
int h[N + 7];

long long dpf (int i, int k) {
	long long &d = dp[i][k];

	if (d != -1) {
		return d;
	}

	if (i > n) {
		return d = 0;
	}

	d = LLINF;

	for (int j = i; j <= min(n, i + k); j++) {
		d = min(d, max(0, h[j + 1] - h[i]) + dpf(j + 1, k - (j - i)));
	}

	return d;
}

int main () {
	memset(dp, -1, sizeof dp);

	int k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	cout << dpf(0, k) << "\n";

	return 0;
}