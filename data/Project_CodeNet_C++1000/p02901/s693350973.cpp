#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, m; cin >> n >> m;
	map<int, int> dp;
	dp[0] = 0;
	for (int i=0; i<m; i++) {
		int a, b; cin >> a >> b;
		
		int k = 0;
		for (int j=0; j<b; j++) {
			int c; cin >> c;
			k += pow(2, c - 1);
		}

		for (auto p : dp) {
			int nk = k | p.first;
			if (dp.count(nk)) dp[nk] = min(dp[nk], p.second + a);
			else dp[nk] = p.second + a;
		}
	}
	int ret = -1;
	int l = pow(2, n) - 1;
	if (dp[l]) ret = dp[l];
	cout << ret << endl;
	return 0;
}