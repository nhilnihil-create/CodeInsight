#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5100;
int k,q,d[N],s[N],n,x,m;
int num(int p)
{
	return x+((p-1)/k)*s[k-1]+s[(p-1)%k];
}
signed main()
{
	scanf("%lld%lld",&k,&q);
	for (int i=0;i<k;i++) scanf("%lld",&d[i]);
	while (q--)
	{
		scanf("%lld%lld%lld",&n,&x,&m);
		n--;
		int cnt=0;
		for (int i=0;i<k;i++) cnt+=(d[i]%m==0);
		cnt=cnt*((n-1)/k);
		for (int i=((n-1)/k)*k+1;i<=n;i++)
		  cnt+=(d[(i-1)%k]%m==0);
		s[0]=d[0]%m;
		for (int i=1;i<k;i++) s[i]=s[i-1]+(d[i]%m);
//		printf("%d\n",num(n));
		cnt+=num(n)/m-x/m;
		printf("%lld\n",n-cnt);
	}
}