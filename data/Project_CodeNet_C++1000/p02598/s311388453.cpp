#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
int main(void)
{
	int n,i,k,a[200000],lo,hi,m,cnt,c;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	hi=a[0];
	for(i=1;i<n;i++)	hi=max(hi,a[i]);
	lo=1;
	while(lo<=hi)	{
		m=(hi+lo)/2;
		cnt=0;
		for(i=0;i<n;i++)	{
			c=a[i]/m;
			if(a[i]%m==0)	c--;
			cnt+=c;
		}
		if(cnt<=k)	hi=m-1;
		else lo=m+1;
	}
	printf("%d\n",lo);
	return 0;
}