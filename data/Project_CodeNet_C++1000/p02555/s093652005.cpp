#include<bits/stdc++.h>
using namespace std;
#define Mod 1000000007
#define Maxn 2010
 
int n;
long long f[Maxn];
 
int main()
{
	scanf("%d", &n);
	if (n < 3) puts("0");
	else
	{
		for (int i=1; i<=n; i++) f[i]=1ll;
		for (int i=6; i<=n; i++)
			for (int j=3; j<=i-3; j++)
				f[i]=(f[i]+f[i-j])%Mod;
		// for (int i=1; i<=n; i++) printf("%d ", f[i]); puts("");
		printf("%lld\n", f[n]);
	}
}