#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define mid ((l+r)>>1)
#define MAXN (int)(2e5+2333)
int a[MAXN];
inline int f(int x,int y) { if (x%y) return (int)(x/y)+1; return x/y; }
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=1e9+1,sum,ans=1e9;
	while (l<r)
	{
		sum=0;
//		printf(";%d %d %d\n",l,mid,r);
		for (int i=1;i<=n;i++) sum+=(f(a[i],mid)-1);
//		printf("--- %d\n",sum);
		if (sum>k) l=mid+1;
		else { ans=mid; r=mid; }
	}
	printf("%d\n",ans);
	return 0;
}
