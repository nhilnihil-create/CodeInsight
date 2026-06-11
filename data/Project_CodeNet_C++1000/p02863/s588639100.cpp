#include <bits/stdc++.h>
using namespace std;
using lint = long long;
typedef pair<lint, lint> P;

signed main(){
	lint N, W; cin >> N >> W;
	vector<P> vec(N);
	for(int i = 0; i < N; i++) cin >> vec[i].first >> vec[i].second;
	sort(vec.begin(), vec.end());
	vector<lint> weight(N), value(N);
	for(int i = 0; i < N; i++) weight[i] = vec[i].first, value[i] = vec[i].second;
	vector<vector<lint> > dp(N + 10, vector<lint> (W + 10, 0));
	for(int i = 0; i < N - 1; i++){
		for(int w = 0; w < W; w++){
			if (w >= weight[i]) {
        if (dp[i + 1][w] < dp[i][w - weight[i]] + value[i]) {
          dp[i + 1][w] = dp[i][w - weight[i]] + value[i];
        }
      }
      if (dp[i + 1][w] < dp[i][w]) {
        dp[i + 1][w] = dp[i][w];
      }
    }
	}
	lint ans = 0;
    for(lint i = 0;i < N; i++){
        ans = max(ans, dp[i][W - 1] + value[i]);
    }
    cout << ans << endl;
}
