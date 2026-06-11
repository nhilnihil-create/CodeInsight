#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],t[N],ans;
int C(int x)
{
	return x*(x-1)/2;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),t[a[i]]++;
	for(int i=1;i<N;i++)
		if(t[i]>=2) ans+=C(t[i]);
	for(int i=1;i<=n;i++)
	{
		if(t[a[i]]<2) printf("%lld\n",ans);
		else printf("%lld\n",ans-(C(t[a[i]])-C(t[a[i]]-1)));
	}
	return 0;
}