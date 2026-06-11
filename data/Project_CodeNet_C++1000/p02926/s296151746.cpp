#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define N 105
#define PI 3.14159265
using namespace std;

typedef long long ll;
ll n, px, py, mx;
ll f(ll p, ll q) {
	return p * p + q * q;
}

struct st {
	ll x, y;
	double ta;
} a[N];

bool comp(st p, st q) {
	return p.ta < q.ta;
}

int main()
{
	ll i, j, t;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf ("%lld %lld", &a[i].x, &a[i].y);
		a[i].ta = atan2(a[i].y, a[i].x);
	}
	sort(a, a + n, comp);
	for (i = 0; i < n; i++) {
		px = a[i].x;
		py = a[i].y;
		for (j = 1; j < n; j++) {
			t = (i + j) % n;
			if (f(px, py) < f(px + a[t].x, py + a[t].y)) {px += a[t].x; py += a[t].y;}
		}
		mx = max(mx, px * px + py * py);
	}
	printf("%.15f\n", sqrt(mx));
    return 0;
}
