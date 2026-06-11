#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define ufor(i,l,r) for (int i=l;i<=r;i++)
#define MAXN 1000500
long long a[MAXN],b[MAXN],c[MAXN];
int X,Y,A,B,C;
long long ans=0;

bool cmp(int x,int y)
{
	return x>y;
}

void init()
{
	scanf("%d%d%d%d%d",&X,&Y,&A,&B,&C);
	ufor (i,1,A) scanf("%lld",&a[i]);sort(a+1,a+1+A,cmp); a[A+1]=0;
	ufor (i,1,B) scanf("%lld",&b[i]);sort(b+1,b+1+B,cmp); b[B+1]=0;
	ufor (i,1,C) scanf("%lld",&c[i]);sort(c+1,c+1+C,cmp); c[C+1]=0;
	//ufor (i,1,A) suma[i]=suma[i-1]+a[i];
	//ufor (i,1,B) sumb[i]=sumb[i-1]+b[i];
	//ufor (i,1,C) sumc[i]=sumc[i-1]+c[i];
	ans=0;
	ufor (i,1,X) ans+=a[i];
	ufor (i,1,Y) ans+=b[i]; 
}
int main()
{
	init();
	//ans=suma[X]+sumb[Y];
	int p=X,q=Y;
	ufor (i,1,X+Y)
	{
		if (p==0 || q==0)
		{
			if (q>0 && c[i]>b[q]) 
				ans+=c[i]-b[q--]; else
			if (p>0 && c[i]>a[p]) 
				ans+=c[i]-a[p--];
			continue;
		} 
		if (a[p]>=b[q] && c[i]>b[q])
			ans+=c[i]-b[q--]; else
		if (a[p]<b[q] && c[i]>a[p])
			ans+=c[i]-a[p--]; else
		break;
	}

	printf("%lld\n",ans);
	return 0;
}
