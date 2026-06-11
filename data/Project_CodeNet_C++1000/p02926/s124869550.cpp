#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 205
using namespace std;

typedef long long ll;
struct st{
	ll x, y;
} a[N];
ll n, sx, sy, mx;

bool cmp(st p, st q) {
	return atan2(1.0 * p.y, 1.0 * p.x) < atan2(1.0 * q.y, 1.0 * q.x);
}

int main()
{
	ll i, j;
	cin >> n;
	for (i = 0; i < n; i++) scanf("%lld %lld", &a[i].x, &a[i].y);
	sort(a, a + n, cmp);
	for (i = 0; i < n; i++) a[n + i] = a[i];
	for (i = 0; i < n; i++) {
		sx = sy = 0;
		for (j = 0; j < n; j++) {
			sx += a[i + j].x;
			sy += a[i + j].y;
			mx = max(mx, sx * sx + sy * sy);
		}
	}
	printf("%.15f", sqrt(1.0 * mx));
    return 0;
}