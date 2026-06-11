#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

/*for(int bit=0; bit<(1<<n);++bit){
rep(j,m){
if(bit>>j&1){
}*/
int dp[1001][10001];
const int INF = 1e9;
int main() {
	int h, n;
	cin >> h >> n;
	vector<int>a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	rep(i, n)rep(j, h+1)dp[i][j] = INF;
	rep(i, n)rep(j, h+1) {
		if (j == 0) {
			dp[i+1][j] = 0;
			continue;
		}
		if (j - a[i] < 0) {
			dp[i + 1][j] = min(dp[i][j], b[i]);
			//cout << "a" << " ";
		}
		else {
			dp[i + 1][j] = min(dp[i + 1][j - a[i]] + b[i], dp[i][j]);
		}
		
		//cout << i + 1 << " " << j << " "<<dp[i + 1][j] << endl;;
	}
	cout << dp[n][h];
	return 0;
}
	