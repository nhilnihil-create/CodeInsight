#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()


const int INF = 1001001001;

int main(){
	int n, t; cin >> n >> t;
	vector<pi> ab(n); rep(i,n) cin >> ab[i].first >> ab[i].second;
	sort(all(ab));
	vector<vi> dp(n+1, vi(t+1, 0));
	dp[0][0] = 0;
	rep(i, n){
		rep(j, t){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			dp[i+1][min(t, j+ab[i].first)] = max(dp[i][min(t,j+ab[i].first)], dp[i][j]+ab[i].second);
		}
	}
	int ans = 0;
	// rep(i,n+1){
	// 	rep(j, t+1){
	// 		cout << dp[i][j] <<" ";
	// 	}
	// 	cout << endl;
	// }
	rep(i,n+1){
		ans = max(ans, dp[i][t]);
	}
	cout << ans << endl;
}