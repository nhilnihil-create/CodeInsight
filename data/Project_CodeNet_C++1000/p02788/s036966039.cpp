#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>

#define LL long long

using namespace std;

const int N = 200010;
int n, D, A;

struct T {
	int x, h;
}a[N];

LL tot[N];

int main() {
	scanf("%d%d%d", &n, &D, &A);

	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].x, &a[i].h);

	sort(a + 1, a + 1 + n, [](const T &p, const T &q) {
		return p.x < q.x;
	});

	LL ans = 0, sum = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && a[j].x - a[i].x <= 2 * D)
			j++;

		sum += tot[i];
		LL t = a[i].h - sum * A;
		if (t > 0) {
			LL c = t / A + (bool)(t % A);
			ans += c;

			sum += c;
			tot[j] -= c;
		}
	}

	printf("%lld\n", ans);

	return 0;
}