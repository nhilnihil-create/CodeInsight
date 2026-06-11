#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;

signed main() {
	// ios::sync_with_stdio(false);
	ll a, b, c;
	scanf("%lld %lld.%lld", &a, &b, &c);
	b = b * 100 + c;
	printf("%lld\n", a * b / 100);
	return 0;
}