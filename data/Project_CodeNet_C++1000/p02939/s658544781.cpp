#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	string s;
	cin >> s;
	s = "$" + s;
	int n = s.size();
	vector<vector<int>>dp(n + 2, vector<int>(2, 0));
	for (int i = 0; i < n ; i++) {
		if (s[i] != s[i + 1]) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + 1);
		}
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + 1);
		dp[i + 2][1] = max(dp[i + 2][1], 1 + dp[i][0]);
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}