#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,x,j,sum,maxv=10000000;//n行 m列 x目标 
	cin>>n>>m>>x;
	int a[n+1][m+1],b[n+1],c[m+1],d[m+1];
	for(int i=0;i<=n;i++)
	b[i]=0;
	for(int i=1;i<=n;i++)
	for(int p=0;p<=m;p++)
	cin>>a[i][p];
	while(b[0]==0)
	{
		j=n;
		while(b[j]==1)
		{
			b[j]=0;
			j--; 
		}
		b[j]=1;
		for(int i=0;i<=m;i++)
		{
			c[i]=0;
			d[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int k=0;k<=m;k++)
			c[k]+=a[i][k]*b[i];
		}
		for(int i=1;i<=m;i++)
		if(c[i]>=x)
		d[i]=0;
		for(int i=1;i<=m;i++)
		d[1]+=d[i];
		if(d[1]==0&&c[0]<maxv)
		maxv=c[0];
	}
	if(maxv==10000000) maxv=-1;
	cout<<maxv;
	return 0;
}