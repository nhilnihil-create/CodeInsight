#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff(i,n) for(i=0;i<n;i++)
ll bg=998244353,arr[4000],dp[4000][4000];
ll power(ll x,ll y)
{
	if(y==0)
		return 1;
	ll h=power(x,y/2)%bg;	
	h=(h*h)%bg;
	if(y%2==1)
	  return (x*h)%bg;
	else
	  return h%bg;  
}
ll modinv(ll m)
{
	return power(m,bg-2)%bg;
}
int main()
{ 
	ll i,n,s,j;
	cin>>n>>s;
	ff(i,n)
	   cin>>arr[i+1];
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
			dp[i][0] = power(2,i)%bg;
			for(j=1;j<=s;j++)	
			{
				dp[i][j]=(dp[i-1][j]*2)%bg;
				if((j-arr[i])>=0)
				  dp[i][j] = (dp[i-1][j-arr[i]] + dp[i][j])%bg;
			}
	}  
	cout<<dp[n][s];    
	return 0;
}