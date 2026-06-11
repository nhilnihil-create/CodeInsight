#include<bits/stdc++.h>
using namespace std;
int n,a[1111111],c,cnt;
char s[1111111];
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n-1;i++)
	{
		a[i]=abs(s[i]-s[i+1]);
	}
	if (n==2)
	{
		printf("%d\n",a[0]);
		return 0;
	}
	for (int i=0;i<n-1;i++)
	{
		if (((n-2)&i)==i)
		{
			if (a[i]==1) c^=1;
		}
	}
	if (c)
	{
		printf("1\n");
		return 0;
	}
	for (int i=0;i<n-1;i++)
	{
		if (a[i]==1)
		{
			printf("0\n");
			return 0;
		}
	}
	c=0;
	for (int i=n-2;i>=0;i--)
	{
		if (((n-2)&i)==i) 
		{
			if (a[i]==2) c^=1;
		}
	}
	if (c) printf("2\n");
	else printf("0\n");
	return 0;
}