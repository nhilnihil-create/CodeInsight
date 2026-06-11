#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	ll nax1 = max(a, b);
	ll nax2 = max(c, d);
	ll nin1 = min(a, b);
	ll nin2 = min(c, d);
	
	printf("%lld\n", max({nax1 * nax2, nax1 * nin2, nin1 * nax2, nin1 * nin2}));
	return 0;
}
