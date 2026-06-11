#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
int main()
{

ll n;
cin>>n;
ll dp[2002];
for(ll i=0;i<2002;i++)
dp[i]=0;
dp[0]=1;dp[1]=0;dp[2]=0;

for(ll i=3;i<2002;i++)
{
	for(ll j=i-3;j>=0;j--)
	{
		dp[i]+=(dp[j])%MOD;
		dp[i]=dp[i]%MOD;
	}
}
/*for(ll i=0;i<=n;i++)
cout<<dp[i]<<endl;*/
cout<<dp[n]<<endl;
return 0;
}
