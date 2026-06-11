#include<iostream>
using namespace std;
int vis[105];
int x,n,t;
int main()
{
	cin>>x>>n;
	for(int i=0;i<n;++i)
	{
		cin>>t;
		vis[t]=1;
	}
	int k1=1005,k2=0;
	for(int i=0;i<=101;++i)
	{
		if((!vis[i])&&abs(i-x)<k1)
		{
			k1=abs(i-x);
			k2=i;
		}
	}
	cout<<k2<<endl;
	return 0;
}