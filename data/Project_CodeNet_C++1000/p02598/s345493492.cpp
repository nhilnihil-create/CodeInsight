#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define MAXN (int)(2e5+2333)
int a[MAXN],asbsummadebysbzzx;
inline int f(int x,int y) { if (x%y) return (int)(x/y)+1; return x/y; }
signed main()
{
	int n,k;
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        asbsummadebysbzzx+=a[i];
    }
    if(!asbsummadebysbzzx)
    {
        cout<<0;
        return 0;
    }
	int l=1,r=1e9,ans=1e9;
	long long sum;
	while (l<r)
	{
		sum=0;
//		printf(";%d %d %d\n",l,mid,r);
		for (int i=1;i<=n;i++) sum+=(f(a[i],mid)-1);
//		printf("--- %d\n",sum);
		if (sum>k) l=mid+1;
		else { ans=min(ans,mid); r=mid; }
	}
	printf("%lld\n",ans);
	return 0;
}
