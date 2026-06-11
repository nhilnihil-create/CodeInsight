#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n;
long long ans;
int main()
{
	scanf("%d",&n);
	ans+=(LL)n*(n+1)*(n+2)/6;
	for (int i=1,x,y;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		ans-=(LL)x*(n-y+1);
	}
	printf("%lld\n",ans);
	return 0;
}
