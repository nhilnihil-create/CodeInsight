#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,dp[20][20];
string ans="";

LL count(LL len)
{
	memset(dp,0,sizeof(dp));
	repn(i,9) dp[0][i]=1;
	rep(i,len-1)
	{
		rep(j,10)
		{
			if(dp[i][j]==0) continue;
			if(j+1<=9) dp[i+1][j+1]+=dp[i][j];
			dp[i+1][j]+=dp[i][j];
			if(j-1>=0) dp[i+1][j-1]+=dp[i][j];
		}
	}
	LL ret=0;
	rep(i,10) ret+=dp[len-1][i];
	return ret;
}

LL conditionalCount(LL fir,LL len)
{
	memset(dp,0,sizeof(dp));
	dp[0][fir]=1;
	rep(i,len-1)
	{
		rep(j,10)
		{
			if(dp[i][j]==0) continue;
			if(j+1<=9) dp[i+1][j+1]+=dp[i][j];
			dp[i+1][j]+=dp[i][j];
			if(j-1>=0) dp[i+1][j-1]+=dp[i][j];
		}
	}
	LL ret=0;
	rep(i,10) ret+=dp[len-1][i];
	return ret;
}

int main()
{
	cin>>n;
	LL len,tmp;
	repn(i,15)
	{
		tmp=count(i);
		if(tmp>=n)
		{
			len=i;
			break;
		}
		n-=tmp;
	}
	for(int i=len;i>0;i--)
	{
		for(int j=(i==len ? 1:ans[ans.size()-1]-'0'-1);j<(i==len ? 10:ans[ans.size()-1]-'0'+2);j++)
		{
			tmp=conditionalCount(j,i);
			if(tmp>=n)
			{
				ans.pb(j+'0');
				break;
			}
			n-=tmp;
		}
	}
	cout<<ans<<endl;
	return 0;
}