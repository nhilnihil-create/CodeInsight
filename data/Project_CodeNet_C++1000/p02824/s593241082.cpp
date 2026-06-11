#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 400100;

int n, v, p;
long long m, a[N];
vector <long long> c;

bool check(int mid) {
	c.clear();
	int cnt = 0;
	long long x = a[mid] + m;
	long long v2 = v;
	for (int i = 0; i < n; i++) {
		if (i == mid) {
			v2--;
			continue;
		}
		if (a[i] > x) {
			v2--;
			cnt++;
			continue;
		}
		if (x - a[i] >= m) {
			v2--;
			continue;
		}
		c.push_back(x - a[i]);
	}
	if (cnt >= p) {
		return false;
	}
	v2 -= (p - cnt - 1);
	if (v2 <= 0) {
		return true;
	}
	long long r = v2 * m;
	for (int i = p - cnt - 1; i < c.size() && i < c.size(); i++) {
		r -= c[i];
	}
	return r <= 0;
}

int main() {

	scanf("%d %lld %d %d", &n, &m, &v, &p);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	sort(a, a + n);
	reverse(a, a + n);

	int low = 0;
	int high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(mid)) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	printf("%d\n", low);

	return 0;

}