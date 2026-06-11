#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll H, N;

ll dp[20002]; // dp[damage] = 最小のcost

int main(){
	cin >> H >> N;
	vector<pii> v(N);
	
	// first = damage, second = cost
	for ( int i = 0; i < N; i++ ){
		cin >> v[i].first >> v[i].second;
	}
	
	for ( int i = 0; i < 20002; i++ ){
		dp[i] = 100000001;
	}
	dp[0] = 0;
	
	
	for ( int i = 0; i < H; i++ ){
		for ( int j = 0; j < N; j++ ){
			int damage = v[j].first;
			ll cost = v[j].second;
			dp[i+damage] = min(dp[i+damage], dp[i]+cost);
			
			//cout << i+damage << " " << dp[i+damage] << endl;
		}
	}
	
	ll cost = LLONG_MAX;
	for ( int i = H; i < 20002; i++ ){
		cost = min( cost, dp[i] );
	}
	cout << cost << endl;
	
	return 0;
}

