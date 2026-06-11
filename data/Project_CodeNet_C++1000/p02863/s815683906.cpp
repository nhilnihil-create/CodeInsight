#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

int dp[3001][3001];


int main(){
	int n, t;
	cin >> n >> t;
	vector<pair<int, int> > a(n+1);
	for (int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < 3001; i++){
		for (int j = 0; j < 3001; j++){
			dp[i][j] = -1;
		}
	}
	

	for (int i = 0; i < t; i++){
		dp[0][0] = 0;
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < t; j++){
			if (dp[i-1][j] != -1){
				dp[i][j] = max(dp[i-1][j], dp[i][j]);
				if (j + a[i].first >= t){
					dp[i][t] = max(dp[i-1][j] + a[i].second, dp[i][t]);
				}else{
					dp[i][j+a[i].first] = max(dp[i-1][j] + a[i].second, dp[i][j+a[i].first]);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= t; j++){
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;
	
	return 0;
}
