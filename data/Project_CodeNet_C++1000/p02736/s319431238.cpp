#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn],sum[maxn],v[maxn],k=2,ans;
char s[maxn];
int main()
{
	scanf("%d%s",&n,s+1);
	for (int i=1;i<=n;i++)
	{
		a[i]=s[i]-'1';
		if (a[i]==1) k=1;
	}
	for (int i=1;i<=n;i++)
	{
		v[i]=(i&1?0:v[i/2]+1);
		sum[i]=sum[i-1]+v[i];
	}
	for (int i=1;i<=n;i++)
	if (sum[n-1]==sum[i-1]+sum[n-i]) ans=(ans+a[i]/k)%2;
	printf("%d\n",ans*k);
return 0;
}