#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=100100;
typedef long long LL;
int a,b,c,x,y;
LL aa[maxn],bb[maxn],cc[maxn];
LL av[maxn],bv[maxn],cv[maxn];
LL ans[3*maxn];
int tot;
int main()
{
	
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for(int i=1;i<=a;++i)
	{
		scanf("%lld",&aa[i]);	
	}
	for(int i=1;i<=b;++i)
	{
		scanf("%lld",&bb[i]);	
	}
	for(int i=1;i<=c;++i)
	{
		scanf("%lld",&cc[i]);	
	}
	sort(aa+1,aa+1+a);
	sort(bb+1,bb+1+b);
	sort(cc+1,cc+1+c);
	for(int i=1;i<=x;++i)
	{
		ans[++tot]=aa[a-i+1];
	}
	for(int i=1;i<=y;++i)
	{
		ans[++tot]=bb[b-i+1];
	}
	for(int i=1;i<=c;++i)
	{
		ans[++tot]=cc[c-i+1];
	}
	sort(ans+1,ans+1+tot);
	int temp=0;LL ret=0;
	for(int i=tot;i>0;--i)
	{
		ret+=ans[i];
		temp++;
		if(temp==x+y)break;
	}
	printf("%lld\n",ret);
	return 0;
}
