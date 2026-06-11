#include<bits/stdc++.h>
using namespace std;
int min1=10005;
int vis[1005];
int ans;
int main()
{
	int x,n,a;
	cin>>x>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		vis[a]=1;
	}
	for(int i=-1000;i<=1000;i++)
	{
		if(vis[i]==0)
		{
			if(abs(x-i)<min1)
			{
				min1=abs(x-i);
				ans=i;
			}
		}
	}
	cout<<ans;
}