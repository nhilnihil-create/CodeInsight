#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n, a, b;
	cin >> n >> a >> b;

	ll ans = n / (a + b) * a;
	n %= a + b;
	ans += min(a, n);
	printf("%lld\n", ans);

}
