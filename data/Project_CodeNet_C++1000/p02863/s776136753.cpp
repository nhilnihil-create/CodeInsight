#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
int dp[3010][3010];

signed main(){
	int n, t; cin >> n >> t;
	vector<P> data(n);
	for(int i = 0; i < n; i++) scanf("%d%d", &data[i].first, &data[i].second);
	sort(data.begin(), data.end());
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= t - 1; j++){
			dp[i + 1][j] = dp[i][j];
			if(j - data[i].first >= 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - data[i].first] + data[i].second);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, dp[i][t - 1] + data[i].second);
	cout << ans << endl;
}
