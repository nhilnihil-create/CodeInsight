#include <iostream>
#include <algorithm>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;

int n;
int a[300000];
int c[300000];
int rc[300001];
int ans[300001];

int main() {
	int i;
	
	cin >> n;
	rep(i, n) { cin >> a[i]; a[i]--; c[a[i]]++; }
	sort(c, c + n);
	rep(i, n) { rc[i + 1] = rc[i] + c[i]; }

	//t回操作できるようなkの最大値を求めて、ほげほげ
	//d[i] = min(c[i], t)とおくとき、Σd[i] >= ktを満たす最大のk
	int k = 1;
	for (int t = n; t >= 1; t--) {
		int p = lower_bound(c, c + n, t) - c;
		int s = (n - p) * t + rc[p];
		int kmax = s / t;
		if (kmax > n) kmax = n;
		for (; k <= kmax; k++) ans[k] = t;
	}
	
	for (i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}