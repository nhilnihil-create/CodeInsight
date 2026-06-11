
#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mod 998244353
#define sz(v) (int)(v).size()

#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

ll add(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a+b)%M;
	return (p+M)%M;
}

ll mul(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a*b)%M;
	return (p+M)%M;
}

ll dp[12][10];

ll solve(ll i,ll num)
{
	if((num<0)||(num>9))
		return 0;
	if(i==11)
		return dp[i][num]=1;
	if(dp[i][num]!=-1)
		return dp[i][num];
	return dp[i][num] = solve(i+1,num)+solve(i+1,num-1)+solve(i+1,num+1);
}

int main()
{
	fastio;
	ll num=1;
	ll k,i,j;
	cin>>k;
	for(i=11;i>=0;i--)
	{
		memset(dp,-1,sizeof(dp));
		for(j=1;j<10;j++)
		{
			ll val = solve(i,j);
			if(k<=val)
				break;
			k-=val;
		}
		if(j!=10)
			break;
	}
	vector<ll> v;
	// for(i=0;i<12;i++)
	// {
	// 	for(j=0;j<10;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;

	// }
	ll pre=j;
	v.pb(j);
	i++;
	for(;i<12;i++)
	{
		for(j=0;j<10;j++)
		{
			if(abs(pre-j)>1)
				continue;
			if(dp[i][j]>=k)
				break;
			k-=dp[i][j];
		}
		// j = max(j-1,0LL);
		v.pb(j);
		pre=j;
		// cout<<j<<" ";
	}
	ll ans=0;
	for(i=0;i<sz(v);i++)
		ans=ans*10+v[i];
	cout<<ans<<endl;
    return 0;
}



