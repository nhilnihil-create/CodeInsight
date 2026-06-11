#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
int main()
{
	scanf("%lld%lld%lld", &n, &a, &b);
	if(abs(a - b) % 2 == 0) printf("%lld\n", abs(a - b) / 2);
	else {
		if(a > b) swap(a, b);
		long long ans = (a - 1) + 1 + abs(a - b) / 2;
		ans = min(ans, n - b + 1 + abs(a - b) / 2);
		printf("%lld\n", ans);
	}
	return 0;
}