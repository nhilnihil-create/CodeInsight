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

LL n,dp[20][20][2];

string Itoa(LL x)
{
	string ret="";
	while(x>0)
	{
		ret.pb(x%10+'0');
		x/=10;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

bool check(LL x)
{
	string t=Itoa(x);
	LL ret=0;
	memset(dp,0,sizeof(dp));
	repn(i,9) dp[0][i][0]=1;
	rep(i,t.size()-1)
	{
		rep(j,10)
		{
			if(dp[i][j][0]==0) continue;
			ret+=dp[i][j][0];
			if(j-1>=0) dp[i+1][j-1][0]+=dp[i][j][0];
			dp[i+1][j][0]+=dp[i][j][0];
			if(j+1<=9) dp[i+1][j+1][0]+=dp[i][j][0];
		}
	}
	memset(dp,0,sizeof(dp));
	repn(i,t[0]-'0'-1) dp[0][i][1]=1;
	dp[0][t[0]-'0'][0]=1;
	rep(i,t.size()-1)
	{
		rep(j,10)
		{
			rep(k,2)
			{
				if(dp[i][j][k]==0) continue;
				if(j-1>=0&& !(k==0&&j-1>t[i+1]-'0')) dp[i+1][j-1][k|(j-1<t[i+1]-'0')]+=dp[i][j][k];
				if(!(k==0&&j>t[i+1]-'0')) dp[i+1][j][k|(j<t[i+1]-'0')]+=dp[i][j][k];
				if(j+1>=0&& !(k==0&&j+1>t[i+1]-'0')) dp[i+1][j+1][k|(j+1<t[i+1]-'0')]+=dp[i][j][k];
			}
		}
	}
	rep(i,10) ret+=dp[t.size()-1][i][1];
	return ret<n;
}

int main()
{
	cin>>n;
	LL lb=1,ub=10000000000,mid;
	while(lb<ub)
	{
		mid=(lb+ub+1)/2;
		if(check(mid)) lb=mid;
		else ub=mid-1;
	}
	cout<<lb<<endl;
	return 0;
}