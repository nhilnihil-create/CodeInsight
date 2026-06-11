#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
signed main(){
	scanf("%lld",&n);
	m=n-1;
	if (m>=2)
	{
		for (register int i=2; i*i<=m; ++i)
		if (m%i==0)
		{
			ans++;
			if (m/i!=i) ans++;
		}
		ans++;
	}
	if (n>=2)
	{
		for (register int i=2; i*i<=n; ++i)
		if (n%i==0)
		{
			int now=n;
			while (now%i==0) now/=i;
			if (now%i==1) ans++;
		}
		ans++;
	}
	printf("%lld\n",ans);
return 0;
}