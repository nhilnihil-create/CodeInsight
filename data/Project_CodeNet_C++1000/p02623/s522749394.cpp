#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,ky,kx,d=0,w=1;
	cin>>n>>m>>ky;
	long long a[n+1];
	long long b[m+1];
	a[0]=0;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]+a[i-1];
		if(a[i]<=ky)
		d=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		b[i]=b[i]+b[i-1];
	}
	for(int i=d;i>=0;i--)
	{
		kx=ky-a[i];
		for(int p=w;p<=m;p++)
		{
			if(b[p]>kx)
			break;
			else if(d<i+p)
			d=i+p;
			w=p;
		}
	}
	cout<<d;
	return 0;
}