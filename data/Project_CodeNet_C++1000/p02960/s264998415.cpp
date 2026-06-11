#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(),s.end());

	vector<int> mod_digit(n);
	mod_digit[0] = 1;
	for(int i = 0;i < n-1;i++){
		mod_digit[i+1] = mod_digit[i] * 10 % 13;
	}
	vector<vector<ll>> dp(n+1,vector<ll>(13,0));
	dp[0][0] = 1;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 13;j++){
			if(s[i] == '?'){
				for(int k = 0;k <= 9;k++){
					dp[i+1][(j+k*mod_digit[i])%13] += dp[i][j];
					dp[i+1][(j+k*mod_digit[i])%13] %= MOD;
				}
			}
			else{
				dp[i+1][(j+(s[i]-'0')*mod_digit[i])%13] += dp[i][j];
				dp[i+1][(j+(s[i]-'0')*mod_digit[i])%13] %= MOD;
			}
		}
	}

	cout << dp[n][5] << endl;
}
