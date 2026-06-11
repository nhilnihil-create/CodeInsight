#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	const int MOD=1e9+7;
	int N,M;
	cin>>N>>M;
	vector<int> dp(N+2,0);
	dp[0]=1;
	map<int,int> m;
	rep(i,M)
	{
		int a;
		cin>>a;
		m[a]=1;
	}
	rep(i,N)
	{
		if(m[i+1]!=1) (dp[i+1]+=dp[i])%=MOD;
		if(m[i+2]!=1) (dp[i+2]+=dp[i])%=MOD;
	}
	cout<<dp[N]<<endl;
	return 0;
}