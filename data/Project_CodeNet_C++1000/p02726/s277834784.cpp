#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define ufor(i,l,r) for (int i=l;i<=r;i++)
#define MAXN 2050
int a[MAXN],d[MAXN][MAXN];
int n;


int main()
{
	int X,Y;
	scanf("%d%d%d",&n,&X,&Y);
	ufor (i,1,n)
	ufor (j,1,n) d[i][j]=abs(i-j);
	d[X][Y]=d[Y][X]=1;
	
	bool flag=true;
	while (flag)
	{
		flag=false;
		ufor (i,1,n)
		ufor (j,1,n)
		{
			int x=min(d[i][X]+d[X][j],d[i][Y]+d[Y][j]);	
			if (x<d[i][j]) d[i][j]=x,flag=true;
		}
	}

	ufor (i,1,n-1)
	ufor (j,i+1,n) a[d[i][j]]++;
	
	ufor (i,1,n-1)
	printf("%d\n",a[i]);
	return 0;
}
