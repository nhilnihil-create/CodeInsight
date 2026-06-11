#include <cstdio>
#include <algorithm>

int main() 
{
	long long n, a, b;
	scanf("%lld%lld%lld", &n, &a, &b);
	if ((a & 1) == (b & 1)) printf("%lld\n", (b - a) >> 1);
	else printf("%lld\n", ((b - a - 1) >> 1) + std::min(n - b + 1, a));
	return 0;
}
