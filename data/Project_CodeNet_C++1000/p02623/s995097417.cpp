#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<ext/pb_ds/priority_queue.hpp>
#include<set>
#include<map>
#include<math.h>
#include<set>
#define maxn 500005
#define lson (now<<1)
#define rson ((now<<1)|1)
typedef long long ll;
using namespace std;
int n,m,k;
ll a[maxn],b[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]),b[i]+=b[i-1];
	int nr=n,ans=0;
	for(int i=1;i<=m;i++)
	{
		while(a[nr]+b[i]>1ll*k && nr>0)
			nr--;
		if(a[nr]+b[i]<=1ll*k)
			ans=max(ans,nr+i);
	}
	
	nr=m;
	for(int i=1;i<=n;i++)
	{
		while(b[nr]+a[i]>1ll*k && nr>0)
			nr--;
		if(b[nr]+a[i]<=1ll*k)
			ans=max(ans,nr+i);
	}
	printf("%d\n",ans);
	
}