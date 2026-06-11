#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 300100;

int n;
long long a[N], s[N], sum = 0;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}

	s[0] = 0;

	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}

	long long res = (long long) 2e18;

	for (int i = 0; i <= n; i++) {
		long long x = s[i];
		long long y = sum - x;
		res = min(res, llabs(x - y));
	}

	printf("%lld\n", res);

	return 0;

}