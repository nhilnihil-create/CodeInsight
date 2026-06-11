#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	ll n, m, v, p, i, a[100003];

	scanf("%lld%lld%lld%lld", &n, &m, &v, &p);
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	sort(a, a + n);

	ll l, r, mid, vs, base, ak, al, rp;
	l = -1;
	r = n - 1;
	while (r - l > 1) {
		mid = (l + r + 1) / 2;
		base = a[mid] + m;
		ak = lower_bound(a, a + n, base) - a;
		al = lower_bound(a, a + n, base + 1) - a;
		if (n - al >= p) {
			l = mid;
			continue;
		}
		rp = p - (n - al) - 1;
		vs = m + m * (n - al);
		for (i = al - 1; i >= 0; i--) {
			if (i == mid) {
				continue;
			}
			if (rp > 0) {
				vs += m;
				rp--;
			}
			else {
				vs += min(m, base - a[i]);
			}
		}
		if (vs >= m * v) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	printf("%lld\n", n - r);

	return 0;
}