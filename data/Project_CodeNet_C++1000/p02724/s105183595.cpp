#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define ufor(i,l,r) for (int i=l;i<=r;i++)
#define MAXN 20000500

int main()
{
	int n;
	scanf("%d",&n);
	int ans=n/500*1000+(n%500)/5*5;
	printf("%d",ans);		
	return 0;
}
