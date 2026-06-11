#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],p[200005],m,d;
bool vis[200005];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	 	cin>>a[i];
	int i=a[1];
	p[0]=1;
	vis[1]=1;
	while(!vis[i])
	{
		vis[i]=1;
		++d;
		p[d]=i;
		i=a[i];
	}
	++d;
	for(int j=0;j<=d;++j)
	{
		if(p[j]==i)
		{
			m=j;
			break;
		}
	}
	if(k<=m)
	{
		cout<<p[k];
		return 0;
	}
	d-=m;
	k=(k-m)%d;
	cout<<p[k+m];
	return 0;
}