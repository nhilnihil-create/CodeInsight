#include <stdio.h>
typedef long long ll;
ll max(ll a, ll b) { return a > b ? a : b; }
int main()
{
	ll a, b, c, d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	ll ans = -1000000000000000001;
	ans = max(ans, a * c);
	ans = max(ans, a * d);
	ans = max(ans, b * c);
	ans = max(ans, b * d);
	printf("%lld", ans);
}