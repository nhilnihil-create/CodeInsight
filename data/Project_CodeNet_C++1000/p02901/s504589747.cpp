#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

signed main(){
	int n, m; cin >> n >> m;
	vector<int> cost(m);
	vector<vector<int> > data(m);
	for(int i = 0; i < m; i++){
		int x; scanf("%d%d", &cost[i], &x);
		for(int j = 0; j < x; j++){
			int y; scanf("%d", &y); data[i].push_back(y - 1);
		} 
	}
	vector<int> dp(1 << n, INF);
	dp[0] = 0;
	for(int bit = 0; bit < (1 << n); bit++){
		for(int j = 0; j < m; j++){
			int num = bit;
			for(int k = 0; k < data[j].size(); k++) num = num | (1 << data[j][k]);
		  dp[num] = min(dp[num], dp[bit] + cost[j]);
		}
	}
	int ans = dp[(1 << n) - 1];
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}