#include <cstdio>

typedef long long ll;

ll myabs(ll a) {
	return a > 0 ? a : -a;
}

int main() {
	ll a, b, v, w, t;
	scanf("%lld%lld%lld%lld%lld", &a, &v, &b, &w, &t);
	ll dif = myabs(a - b);
	if (dif > t * (v - w))
		puts("NO");
	else
		puts("YES");
	return 0;
}
