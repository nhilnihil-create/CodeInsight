#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<deque>
#include<cctype>
#include<cstring>
using namespace std;
int v,p,n,ans;
long long m,a[100050],a1;
int main()
{
	scanf("%d %lld %d %d",&n,&m,&v,&p);
	ans=p;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);a[i]=-a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=-a[i];
	}
	for(int i=p+1;i<=n;i++)
	{
		if(a[i]+m<a[p])break;
		if(v<=p+n-i)++ans;
		else if(((v-p-n+i)*m-a1-1)/(i-p)+1+a[p]<=a[i]+m)++ans;
		a1+=a[p]-a[i];
	}
	printf("%d\n",ans);
	return 0;
}