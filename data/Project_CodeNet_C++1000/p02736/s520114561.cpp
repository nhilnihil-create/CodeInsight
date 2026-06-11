#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long lol;
int fac2[1000005],flag0,flag1,flag2;
int n,sum,a[1000005];
char s[1000005];
int get(int i,int v)
{
	if (i>n) return 0;
	if (fac2[n-1]-fac2[n-i]-fac2[i-1]==0) return v;
	return 0;
}
int main()
{int i;
	scanf("%d",&n);
	scanf("%s",s+1);
	for (i=1;i<=n;i++)
	{
		a[i]=s[i]-'1';
		if (a[i]==0) flag0=1;
		if (a[i]==1) flag1=1;
		if (a[i]==2) flag2=1;
	}
	fac2[1]=0;
	for (i=2;i<=n;i++)
	{
		//printf("%d\n",a[i]);
		if (i%2==0)
		fac2[i]=fac2[i/2]+1;
	}
	for (i=1;i<=n;i++)
	fac2[i]+=fac2[i-1];
	if (flag0+flag1+flag2==1) printf("0\n");
	else 
	{
		if (flag2==1&&flag0==1&&flag1==0)
		{
			for (i=1;i<=n;i++)
			if (a[i]==2) sum^=get(i,2);
			printf("%d",sum);
		}
		else
		{ 
			if (flag2==1&&flag1==1&&flag0==0) 
			for (i=1;i<=n;i++)
			a[i]--;
			if (flag2==1&&flag1==1&&flag0==1) 
			for (i=1;i<=n;i++)
			if (a[i]==2) a[i]=0;
			
			for (i=1;i<=n;i++)
			if (a[i]==1) sum^=get(i,1);
			printf("%d",sum);
		}
	}
}