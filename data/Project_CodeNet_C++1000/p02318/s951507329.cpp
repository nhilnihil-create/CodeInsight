#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
const int INF = 1 << 25;
int dp[1001][1001];
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	fill((int*)dp, (int*)(dp + 1001), INF);
	for (int i = 0; i <= s1.size(); i++) dp[i][0] = i;
	for (int i = 0; i <= s2.size(); i++) dp[0][i] = i;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
		}
	}
	cout << dp[s1.size()][s2.size()] << endl;
}