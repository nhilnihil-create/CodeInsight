#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

ll dp[3005][6005];

int main(){
	ll n,t;
	cin >> n >> t;
	vector<pair<ll,ll>> p(n);
	rep(i,n){
		cin >> p[i].first >> p[i].second;
	}
	sort(p.begin(),p.end());
	dp[0][0] = 0;
	dp[0][p[0].first] = p[0].second;
	REP(i,n-1){
		rep(time, t){
			int a = p[i].first;
			int b = p[i].second;
			dp[i][time+a] = max(dp[i][time+a], dp[i-1][time] + b);
			dp[i][time] = max(dp[i][time], dp[i-1][time]);
		}
	}
	ll ans = 0;
	rep(i,n){
		rep(time, 6005){
			ans = max(ans, dp[i][time]);
		}
	}
	cout << ans << endl;
	return 0;
}

