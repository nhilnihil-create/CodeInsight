#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, m, v, p;
ll a[100021];

bool Cmp(int x, int y) {
	return x > y;
}

bool Valid(int d) {
	if (d <= p) return true;
	for (int i = d; i >= 1; --i) {
		if (a[i] != a[d]) {
			d = i + 1;
			break;
		}
	}
	ll s = (p + n - d) * m;
	for (int i = p; i < d; ++i) {
		if (a[d] + m < a[i]) return false;
		s += (a[d] + m - a[i]);
	}
	return s >= m * v;
}

int main() {
	scanf("%lld%lld%lld%lld", &n, &m, &v, &p);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, Cmp);
	// for (int i = 1; i <= n; ++i)
		// printf("%d ", a[i]);
	// printf("\n");
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (Valid(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}