#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll m,n,yy[3005],money[3005],dp[10005],vis[20]; 

int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=5000;++i) dp[i]=1e15;
    ll a=1<<m,b,c;
    for(int i=0;i<n;++i)
    {
    	cin>>money[i]>>yy[i];
    	ll s=0;
    	for(int j=1;j<=yy[i];++j) 
    	{
    		cin>>b;vis[b]=1;
    		s+=1<<(b-1);
		}
		yy[i]=s;
	}
	for(int i=1;i<=m;++i) if(!vis[i]) {cout<<-1; return 0;} 
	for(int i=0;i<a-1;++i)
	{
		for(int j=0;j<n;++j)
		{
			dp[i|yy[j]]=min(dp[i|yy[j]],dp[i]+money[j]);
		}
	}
	cout<<dp[a-1];
	return 0;
}