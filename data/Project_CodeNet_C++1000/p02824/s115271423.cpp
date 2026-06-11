#include <iostream>
#include <algorithm>
#define int long long

using namespace std;
const int N = 1e5 + 5;

int n, m, v, p;
int a[N], t[N];

bool judge(int x) {
	if (x <= p) return 1;
	if (a[x] + m < a[p]) return 0;
//	if (v <= p - 1 && a[x] + m >= a[p]) return 1;
	for (register int i = 1; i <= n; i++)
		t[i] = a[i];
	for (register int i = 1; i < p; i++)
		t[i] += m;
	
	int cost = m * (p - 1);
	for (register int i = n, c = v - p; i > x && c; c--)
		cost += m, t[--i] += m;
	cost += m;
	
	int left = m * v - cost;
	for (register int i = p; i < x; i++) {
		int inc = min(m, max(a[x] + m - a[i], 0ll));
		inc = min(inc, left);
		left -= inc, t[i] += inc;
	}
	
	return a[x] + m >= t[p] && left <= 0;
}

signed main() {
	cin >> n >> m >> v >> p;
	for (register int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + 1 + n, greater<int>());
	
	int l = 1, r = n, ret = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (judge(mid)) ret = mid, l = mid + 1;
		else r = mid - 1;
	}
	
	cout << ret << endl;
	return 0;
}