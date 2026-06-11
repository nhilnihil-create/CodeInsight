#include<bits/stdc++.h>
using namespace std;

long long int n,k,i,x,y,ans,mod;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;ans=0;mod=1e9+7;
	for (i=k;i<n+2;i++)
	{
		ans=ans-(i*i-i)/2+1;
		x=n+1-i;
		ans=ans+(n*n+n)/2-(x*x-x)/2;
		ans=ans%mod;
	}
	cout<<ans;
}
