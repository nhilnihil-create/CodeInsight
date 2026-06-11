#include <bits/stdc++.h>
 
using namespace std;
 
long long int dp[1000005][2];
 
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	string s;
 
	cin >> s;
 	
	for(int i=0;i<1000005;i++)
	{
		dp[i][0] = 1e18;
		dp[i][1] = 1e18;
	}

	dp[0][0] = s[0] - '0';
	dp[0][1] = 10 - (s[0] - '0');

	for(int i=1;i<s.length();i++)
	{
		dp[i][0] = min(dp[i-1][0] + (s[i]-'0'),dp[i-1][1] + (s[i]-'0') + 1);
		dp[i][1] = min(dp[i-1][0] + (10 - (s[i]-'0')),dp[i-1][1] + (10 - (s[i]-'0'+1)));
	}
 
	cout << min(dp[s.length()-1][0],dp[s.length()-1][1] + 1) << '\n';
 
	return 0;
}