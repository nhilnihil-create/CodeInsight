#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[2][10005];
const int INF = 1e9;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, n;
	cin >> h >> n;
	rep(i,2)rep(j,10005) dp[i][j] = INF;
	dp[0][0] = 0;
	rep(i,n){
		int a, b;
		cin >> a >> b;
		rep(j,h+1){
			chmin(dp[(i+1)%2][j], dp[i%2][j]);
			chmin(dp[i%2][min(j+a, h)], dp[i%2][j] + b);
		}
	}
	cout << dp[n%2][h] << endl;
	return 0;
}