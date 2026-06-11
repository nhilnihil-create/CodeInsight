#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
int minimum(int a, int b) { return a < b ? a : b; }
int maximum(int a, int b) { return a > b ? a : b; }
const long long mod = 1000000007;
//const long long mod = 998244353;


int main() {
	int k, q;
	scanf("%d %d", &k, &q);
	auto d = new int[k];
	auto a = new int[q];
	for (int i = 0; i < k; i++)scanf("%d", d + i);
	for (int i = 0; i < q; i++) {
		int n, x, m;
		scanf("%d %d %d", &n, &x, &m);
		long long round = 0, hasuu;
		for (int j = 0; j < k; j++) {
			if (j == (n - 1) % k)hasuu = round;
			round += d[j] % m == 0 ? m : d[j] % m;
		}
		long long sigma = x % m + round * ((n - 1) / k) + hasuu;
		a[i] = n - ((sigma) / m) - 1;
	}
	for (int i = 0; i < q; i++)printf("%d\n", a[i]);
	return 0;
}