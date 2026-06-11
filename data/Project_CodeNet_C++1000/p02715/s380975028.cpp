#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const ll m=1e9+7;

ll power(ll a,ll b)
{
	if(b==0)
		return 1;

	else if(b%2==0)
		return power((a%m*a%m)%m,b/2);
	else
		return (a*power((a%m*a%m)%m,(b-1)/2))%m;
}

int main()
{
	int n,k;
	cin>>n>>k;

	ll dp[k+1];


	for(int i=k;i>=1;i--)
	{
		dp[i]=power((k/i),n);

		for(int j=2*i;j<=k;j=j+i)
		{
			dp[i]=dp[i]-dp[j];
		}
	}

	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		ans=ans+dp[i]*i;
	}
	cout<<ans%m<<endl;

	return 0;
}