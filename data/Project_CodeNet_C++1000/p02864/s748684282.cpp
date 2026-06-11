#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 300 + 5;
ll h[N], f[N][N];

int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	for (ll i = 1; i <= n; ++i)
		scanf("%lld",&h[i]);
	memset(f,INF,sizeof(f));
	for(ll i = 1; i <= n; ++i)
		f[i][1] = h[i];
	//f记录最少次数 
	for(ll i = 2; i <= n; ++i)
		for(ll j = 2; j <= i; ++j)
			for(ll p = 1; p < i; ++p) 
				f[i][j] = min(f[i][j], f[p][j - 1] + max(0LL, h[i] - h[p]));
	ll ans = f[0][0];
	for(ll i = n - k; i <= n; ++i)
		ans = min(ans, f[i][n - k]);
	if(n == k)
		printf("0\n");
	else 
		printf("%lld\n",ans);
	return 0;
}