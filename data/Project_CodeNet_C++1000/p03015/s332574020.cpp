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

ll dp[100001][2];


int main(){
	string s;
	cin >> s;


	dp[0][0] = 1;
	dp[0][1] = 2;

	for (int i = 1; i < s.length(); i++){
		if (s[i] == '0'){
			dp[i][0] += dp[i-1][0]*3;
			dp[i][1] += dp[i-1][1];
		}else{
			dp[i][0] += dp[i-1][0]*3;
			dp[i][0] += dp[i-1][1];
			dp[i][1] += dp[i-1][1]*2;
		}
		dp[i][0] %= MOD;
		dp[i][1] %= MOD;
	}
	cout << (dp[s.length()-1][0] + dp[s.length()-1][1])%MOD << endl;
	return 0;
}