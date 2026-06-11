#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a, b, n;
	scanf("%lld%lld%lld", &a, &b, &n);
	
	if (n >= b - 1) printf("%lld\n", a * (b - 1) / b);
	else printf("%lld\n", a * n / b);
}
