#include <cstdio>
#include <algorithm>

int main() 
{
	int a;
	long long b, n;
	scanf("%d%lld%lld", &a, &b, &n);
	printf("%lld\n", a * std::min(b - 1, n) / b);
	return 0;
}
