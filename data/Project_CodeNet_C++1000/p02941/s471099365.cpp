#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;
int n, a[maxn + 3], b[maxn + 3], lst[maxn + 3], nxt[maxn + 3];
queue<pair<int, pair<int, int> > > H;

void insert(int i) {
	if (b[i] - b[lst[i]] - b[nxt[i]] >= a[i]) {
		H.push(make_pair(b[lst[i]] + b[nxt[i]], make_pair(i, b[i])));
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; i++) {
		lst[i] = i - 1, nxt[i] = i + 1;
	}
	nxt[n] = 1, lst[1] = n;
	for (int i = 1; i <= n; i++) {
		insert(i);
	}
	ll ans = 0;
	while (!H.empty()) {
		pair<int, pair<int, int> > top = H.front();
		H.pop();
		int x = top.first, i = top.second.first, v = top.second.second;
		if (b[i] != v) {
			continue;
		}
		int t = (b[i] - a[i]) / x;
		b[i] -= t * x, ans += t;
		insert(lst[i]), insert(nxt[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			puts("-1");
			return 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}