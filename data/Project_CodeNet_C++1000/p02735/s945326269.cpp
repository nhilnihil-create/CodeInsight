#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1000 * 1000 * 1000 + 7;
ll mul(ll a, ll b)
{
	return ((a%mod)*(b%mod))%mod;
}
ll add(ll a, ll b)
{
	return ((a%mod)+(b%mod))%mod;
}
ll sub(ll a, ll b)
{
	return ((a%mod)-(b%mod)+mod)%mod;
}
ll n,m;
ll a[102][102];
ll dp[102][102];
ll ch(ll x, ll y)
{
	if(dp[x][y]!=-1)
	{
		return dp[x][y];
	}
	if(x==0 && y==0)
	{
		dp[x][y]=0;
		return dp[x][y];
	}
	if(x==0)
	{
		if(a[x][y-1]==1 && a[x][y]==0)
		{
			dp[x][y]=1;
		}
		else
		{
			dp[x][y]=0;
		}
		dp[x][y]+=ch(x,y-1);
		return dp[x][y];
	}
	if(y==0)
	{
		if(a[x-1][y]==1 && a[x][y]==0)
		{
			dp[x][y]=1;
		}
		else
		{
			dp[x][y]=0;
		}
		dp[x][y]+=ch(x-1,y);
		return dp[x][y];
	}
	ll u1,u2;
	if(a[x-1][y]==1 && a[x][y]==0)
	{
		u1=1;
	}
	else
	{
		u1=0;
	}
	u1+=ch(x-1,y);;
	if(a[x][y-1]==1 && a[x][y]==0)
	{
		u2=1;
	}
	else
	{
		u2=0;
	}
	u2+=ch(x,y-1);;
	dp[x][y]=min(u1,u2);
	return dp[x][y];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(ll j=0;j<s.size();j++)
		{
			dp[i][j]=-1;
			if(s[j]=='.')
			{
				a[i][j]=0;
			}
			else
			{
				a[i][j]=1;
			}
		}
	}
	ll u;
	if(a[n-1][m-1]==1)
	{
		u=ch(n-1,m-1)+1;
	}
	else
	{
		u=ch(n-1,m-1);
	}
	cout<<u;
}
