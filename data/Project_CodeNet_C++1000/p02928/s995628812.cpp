#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2010;
const int MOD = (int) 1e9 + 7;

int n, k, a[N];

int main() {

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	long long d = (k - 1LL) * (k - 0LL) / 2LL;
	long long res = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] > a[j]) {
				res += ((i < j) ? k : 0);
				res += d;
				res %= MOD;
			}
		}
	}

	printf("%lld\n", res);

	return 0;

}