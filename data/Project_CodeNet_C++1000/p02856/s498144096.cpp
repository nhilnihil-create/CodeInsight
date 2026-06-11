#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d, s;

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);
		d += b; s += b * a;
	}
	printf("%lld\n", (ll)(d - 1 + ceil((s - 9) / 9.0)));
	return 0;
}