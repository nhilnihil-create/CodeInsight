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
#define maxn 10000005
#define lson (now<<1)
#define rson ((now<<1)|1)
typedef long long ll;
using namespace std;
int n,m,k;
int f[maxn];
int main()
{
	for(int i=1;i<=1e7;i++)
	{
		for(int j=i;j<=1e7;j+=i)
			f[j]++;
	}
	scanf("%d",&n);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=1ll*i*f[i];
	}
	printf("%lld\n",ans);
}