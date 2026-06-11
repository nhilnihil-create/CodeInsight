#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using namespace std;

const long long mod = 1e9 + 7;
int dp[100100];

int main(){

	cin.tie(0);
	ios::sync_with_stdio(false);
	
	//cout << fixed << setprecision(1) << endl;
	
	memset(dp,0,sizeof(dp));
	
	int n , m;
	cin >> n >> m;
	vector<int> ng(m);
	
	for(int i = 0; i < m; i++){
		cin >> ng[i];
		dp[ng[i]] = -1;
	}
	
	for(int i = n; i >= 0; i--){
		if(i == n){
			dp[i] = 1;
		}
		if(dp[i] == -1)continue;
		if(dp[i + 1] != -1){
			dp[i] += dp[i + 1];
			dp[i] %= mod;
		}
		if(dp[i + 2] != -1){
			dp[i] += dp[i + 2];
			dp[i] %= mod;
		}
	}
	cout << dp[0] << endl;
		
	return 0;
}
 