
// E - Who Says a Pun?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int dp[5000][5000];

int main() {
	int N;
	string S;

	cin >> N;
	cin >> S;

	for (int i=S.size()-1; i>=0; i--) {
		for (int j=S.size()-1; j>=0; j--) {
			if (S[i] ==S[j]) {
				dp[i][j]++;
				if (i != 0 && j != 0) {
					dp[i-1][j-1] += dp[i][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i=0; i < S.size(); i++) {
		for (int j=i; j < S.size(); j++) {
			if (i + dp[i][j] <= j) {
				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans << endl;

	/*
	// **** debug ****
	for (int i=0; i < S.size(); i++) {
		for (int j=0; j < S.size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}