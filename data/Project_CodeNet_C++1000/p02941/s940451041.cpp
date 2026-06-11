#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 400100;

int n, l = 0, r = 0, a[N], b[N], q[N];
bool w[N];

void add(int id) {
	if (w[id]) {
		return;
	}
	int pr = (id + n - 1) % n;
	int nx = (id + 1) % n;
	if (b[id] - a[id] < b[pr] + b[nx]) {
		return;
	}
	w[id] = true;
	q[r++] = id;
	r %= N;
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < n; i++) {
		w[i] = false;
	}

	for (int i = 0; i < n; i++) {
		add(i);
	}

	long long ans = 0;

	while (l != r) {
		int id = q[l++];
		l %= N;
		w[id] = false;
		int pr = (id + n - 1) % n;
		int nx = (id + 1) % n;
		int k = (b[id] - a[id]) / (b[pr] + b[nx]);
		if (k <= 0) {
			continue;
		} 
		ans += k;
		b[id] -= k * (b[pr] + b[nx]);
		add(pr);
		add(nx);
	}

	for (int i = 0; i < n; i++) {
		if (b[i] != a[i]) {
			puts("-1");
			exit(0);
		}
	}

	printf("%lld\n", ans);

	return 0;

}