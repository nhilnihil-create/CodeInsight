#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 100;
int a[N], n, m, v, p;
bool check(int x) {
	if (x <= p) return 1;
	if (a[x] + m < a[p]) return 0;
	long long cnt = 0;
    for (int i = n; i >= p; i--) {
        if (i == x) continue;
        cnt += min(m, a[x] + m - a[i]);
    }
	if (1ll * (p-1) * m + cnt + m >= 1ll * v * m) return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> v >> p;//swap(m,v);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
	int l = 1, r = n;
   // for (int i = 1; i <= n; i++) cout << a[i] << " ";cout << endl;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
        //cout << l << " " << r << endl;
		if (check(mid)) l = mid;
		else r = mid - 1;;
	}
	cout << l << endl;
}