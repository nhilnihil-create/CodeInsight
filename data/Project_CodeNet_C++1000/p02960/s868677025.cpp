#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;



int main()
{
	const int MOD=1e9+7;
	string S;
	cin>>S;
	reverse(S.begin(),S.end());
	int N=S.size();
	vector<vector<int>> dp(N+1,vector<int>(13,0));
	int x=1;
	dp[0][0]=1;
	rep(i,N)
	{
		if(S[i]=='?')
		{
			rep(j,10)
			{
				rep(k,13)
				{
					(dp[i+1][(j*x+k)%13]+=dp[i][k])%=MOD;
				}
			}
		}
		else
		{
			rep(j,13)
			{
				(dp[i+1][((S[i]-'0')*x+j)%13]+=dp[i][j])%=MOD;
			}
		}
		(x*=10)%=13;
	}
	cout<<dp[N][5]<<endl;
	return 0;
}
