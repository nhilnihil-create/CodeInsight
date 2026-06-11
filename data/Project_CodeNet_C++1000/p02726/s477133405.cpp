#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=20100;
int n,x,y;
int ans[maxn];
int main()
{
	
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			int k=min(j-i,abs(x-i)+1+abs(j-y));
			k=min(k,abs(x-j)+1+abs(y-i));
			ans[k]++;
		}
	}
	for(int i=1;i<n;++i)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
