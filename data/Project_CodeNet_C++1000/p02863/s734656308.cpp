#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[3005][6005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	vector<P> x;
	rep(i,n){
		int a, b;
		cin >> a >> b;
		x.emplace_back(a, b);
	}
	sort(x.begin(), x.end());
	memset(dp, 0, sizeof(dp));
	rep(i,n){
		rep(j,t){
			chmax(dp[i+1][j], dp[i][j]);
			chmax(dp[i+1][j+x[i].first], dp[i][j] + x[i].second);
		}
		for(int j = t; j < 6005; j++){
			chmax(dp[i+1][j], dp[i][j]);
		}
	}
	int ans = 0;
	rep(j,6005){
		chmax(ans, dp[n][j]);
	}
	cout << ans << endl;
	return 0;
}