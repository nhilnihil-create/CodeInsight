#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n;
	ll d;
	scanf("%d %lld", &n, &d);
	d *= d;

	int ans = 0;
	while(n--) {
		ll x, y;
		scanf("%lld %lld", &x, &y);
		ans += x * x + y * y <= d;
	}
	printf("%d\n", ans);
}
