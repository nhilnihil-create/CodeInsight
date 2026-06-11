#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;

int n, k;
LL h[302];
LL Sdh[302];

LL dp[302][301] = {};

void solve() {
	cin >> n >> k;
	rep(i, n) cin >> h[i + 1];
	rep(i, n + 1) Sdh[i + 1] = abs(h[i] - h[i + 1]);
	rep(i, n + 1) Sdh[i + 1] += Sdh[i];

	for (int i1 = 1; i1 <= n + 1; i1++) {
		for (int i2 = 0; i2 <= k; i2++) {
			LL Mp = 0;
			for (int kp = 0; kp <= i2 && kp <= i1 - 1; kp++) {
				int j = i1 - kp - 1;
				LL p = Sdh[i1] - Sdh[j] - abs(h[i1] - h[j]);
				Mp = max(Mp, dp[j][i2 - kp] + p);
			}
			dp[i1][i2] = Mp;
		}
	}

	cout << (Sdh[n + 1] - dp[n + 1][k]) / 2 << endl;
}

int main() {

	solve();

	return 0;
}
