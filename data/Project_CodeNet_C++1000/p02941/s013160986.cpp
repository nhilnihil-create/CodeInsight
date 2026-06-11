#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 9;

int n, a[N], b[N];

inline int nxt(int x) {
	return x == n ? 1 : x + 1;
}

inline int lxt(int x) {
	return x == 1 ? n : x - 1;
}

typedef pair<int, int> P;

priority_queue<P> que;

void solve() {
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		que.push(make_pair(b[i], i));
	}
	while (!que.empty()) {
		P top = que.top(); que.pop();
		int x = top.second;
		if (a[x] == b[x]) continue;
		int p = b[lxt(x)] + b[nxt(x)];
		if (b[x] - p < a[x]) {
			puts("-1");
			return ;
		} else {
			int d = (b[x] - a[x]) / p;
			ans += d;
			b[x] -= d * p;
			que.push(make_pair(b[x], x));
		}
	}
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 	
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	solve();
	return 0;
}