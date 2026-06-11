#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=200100;
typedef long long LL;
int n,a[maxn];
LL ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int now=n-1,t=0;ans+=a[n];
	for(int i=n-2;i;--i)
	{	
		if(t==2)
		{
			now--;
			t=0;
		}
		ans+=a[now];
		t++;
		//cout<<ans<<endl;
	}
	printf("%lld\n",ans);
	return 0;
}
