#include <cstdio>
#define ll long long
using namespace std;
 
const ll md = 1e9 + 7;
 
ll q(ll a, int b)
{
	ll ans = 1, x = a;
	while (b)
	{
		if (b & 1)
			ans = (ans * x) % md;
		x = (x * x) % md;
		b >>= 1;
	}
	
	return ans;
}
 
int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld\n", ((q(10ll, n) + q(8ll, n)) % md - (q(9ll, n) << 1) % md + md) % md);
	
	return 0;
}