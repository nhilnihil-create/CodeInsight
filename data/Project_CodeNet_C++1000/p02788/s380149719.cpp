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

LL f[N];

int nxt[N];

void update(int x, LL y) {
	for (; x <= n; x += x & -x)
		f[x] += y;
}

LL query(int x) {
	LL tot = 0;
	for (; x; x -= x & -x)
		tot += f[x];

	return tot;
}

int main() {
	scanf("%d%d%d", &n, &D, &A);

	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].x, &a[i].h);

	sort(a + 1, a + 1 + n, [](const T &p, const T &q) {
		return p.x < q.x;
	});

	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && a[j].x - a[i].x <= 2 * D)
			j++;

		nxt[i] = j;
	}

	LL ans = 0;

	for (int i = 1; i <= n; i++)
		update(i, a[i].h - a[i - 1].h);

	for (int i = 1; i <= n; i++) {
		LL t = query(i);
		if (t > 0) {
			LL c = t / A + (bool)(t % A);
			ans += c;

			update(i, -c * A);
			update(nxt[i], c * A);
		}
	}

	printf("%lld\n", ans);

	return 0;
}