#include "bits/stdc++.h"
using namespace std;
const int INF = 1001001001;
int main() {
	int N;
	cin >> N;
	string S;
	cin >> S;

	int res = 0;
	vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));
	for (int n = 0;n<N;++n) {
		for (int m = 0;m<N;++m) {
			if (S[n] == S[m]) {
				dp[n + 1][m + 1] = dp[n][m] + 1;
				res = max(res, min(dp[n + 1][m + 1],m-n)); 
				//abcabcxxxx
				//xxxabcabcx
			}
		}
	}
	cout << res << endl;
	return 0;
}