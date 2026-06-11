#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007

ll dp[2010][2010];

void chmax(ll& a, ll b) {
	a = max(a, b);
}

int main() {
	for (int i = 0;i < 2010;i++) {
		for (int j = 0;j < 2010;j++) {
			dp[i][j] = 0;
		}
	}
	ll N, X;
	cin >> N;
	vector<pair<ll, int>> A(N);
	for (int i = 0;i < N;i++) {
		cin >> X;
		A[i] = { X,i };
	}
	sort(all(A));
	reverse(all(A));
	for (int i = 0;i < N;i++) {
		for (int j = 0, k = i;k >= 0;j++, k--) {
			chmax(dp[j + 1][k], dp[j][k] + A[i].first * (ll)abs(j - A[i].second));
			chmax(dp[j][k + 1], dp[j][k] + A[i].first * (ll)abs(N - 1 - k - A[i].second));
		}
	}
	ll ans = 0;
	for (int j = 0, k = N;k >= 0;j++, k--) {
		chmax(ans, dp[j][k]);
	}
	cout << ans << endl;
}