#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n;
ll a[105];
ll dp[105];
ll ans;
int main()
{
	ll i,j,k;
	cin>>n;
	ans=1000;
	ll x,y;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	for(i=0;i<n-1;i++)
	{
		
		if(a[i]<a[i+1])
		ans=ans+(ans/a[i])*(a[i+1]-a[i]);
	}
	cout<<ans;
	return 0;
}