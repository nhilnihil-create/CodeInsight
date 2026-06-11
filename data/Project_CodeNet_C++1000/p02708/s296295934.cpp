#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = (ll) 1e18;
const ll mod = (ll) 1e9+7;

ll sum(int n)
{
	ll k = n;
	return (k*(k+1))/2;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	ll ans = 0;
	for(int i = k; i <= n+1; i++) {
		ans += sum(n) - sum(n-i) - sum(i-1)+1;
		ans %= mod;
	}
	printf("%lld\n", ans);
}
