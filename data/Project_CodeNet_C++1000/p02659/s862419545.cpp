#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 10;

signed main() {
	// ios::sync_with_stdio(false);
	ll a, b, c;
	scanf("%lld %lld.%lld", &a, &b, &c);
	b = b * 100 + c;
	ll x = a * b;
	string ans;
	while (x) ans += x % 10 + '0', x /= 10;
	if (ans.size() <= 2) printf("0\n");
	else {
		for (int i = ans.size() - 1; i > 1; i--)
			printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}