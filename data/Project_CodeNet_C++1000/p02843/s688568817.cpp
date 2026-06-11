#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int X;
	cin>>X;
	vector<bool> dp(X+1,false);
	dp[0]=true;
	rep(i,6)
	{
		rep(j,X-(100+i)+1)
		{
			if(dp[j]) dp[j+100+i]=dp[j];
		}
	}
	if(dp[X]) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	return 0;
}
