#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define mod 1000000007

int main()
{
	FASTIO
	string s;
	cin >> s;
	int n = s.size();
	
	ll dp[100005][13];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	
	for(int i=0; i<n; i++)
	{
		int p;
		if(s[i] == '?') p = -1;
		else p = s[i]-'0';
		
		for(int j=0; j<10; j++)
		{
			if(p != -1 && j != p) continue;
			for(int k=0; k<13; k++)
			{
				dp[i+1][(k*10+j)%13] += dp[i][k];
			}
		}
		for(int j=0; j<13; j++) dp[i+1][j] %= mod;
	}
	cout << dp[n][5] << "\n";
	
	return 0;
}