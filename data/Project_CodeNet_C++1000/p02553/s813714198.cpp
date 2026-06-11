#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
	ll a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	printf("%lld\n", max(max(a * c, a * d), max(b * c, b * d)));
	
	return 0;
}