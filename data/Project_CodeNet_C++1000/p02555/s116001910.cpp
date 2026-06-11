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

int main(){
	int s;
	cin >> s;
	const long long mod = 1e9 + 7;
	vector<long long> dp(s + 1 , 0);
	dp[0] = 1;
	for(int i = 3; i <= s; i++){
		for(int j = i - 3; j >= 3; j--){
			dp[i] += dp[j];
			dp[i] %= mod;
		}
		dp[i] += dp[0];
	} 
	cout << dp[s] << endl;
	return 0;
}
 