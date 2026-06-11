#include<cstring>
#include<algorithm>
#include<string>
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int T,n,m;
int a[2010][2010];
int read()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	int x,y,z;
	n=read();
	m=read();
	x=read();
	y=read();
	if(x>m/2||y>n/2)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=x;j++)
	{
		a[i][j]=1;
	}
	for(int i=1;i<=y;i++)
	for(int j=1;j<=m;j++)
	{
		a[i][j]=(a[i][j]==0)?1:0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
	
	return 0;
}