#include <iostream>
#include <string>
#define INF 1e+9
using namespace std;

int main(){
	int dp[1001][1001] = {};
	string s1,s2;
	cin >> s1 >> s2;
	for(int i = 0;i < s1.length();i++){
		for(int j = 0;j < s2.length();j++){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for(int i = 1;i <= s1.length();i++) dp[i][0] = i;
	for(int i = 1;i <= s2.length();i++) dp[0][i] = i;
	for(int i = 1;i <= s1.length();i++){
		for(int j = 1;j <= s2.length();j++){
			if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else{
				dp[i][j] = min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
			}
		}
	}
	cout << dp[s1.length()][s2.length()] << endl;
	return 0;
}