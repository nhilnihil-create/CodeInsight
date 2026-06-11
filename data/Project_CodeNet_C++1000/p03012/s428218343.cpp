#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
const int inf = 1e9; //1(1倍)e(指数)9(10^9)
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> w(n);
	rep(i, n) scanf("%d", &w[i]);
	int ans = inf;
	for(int t = 1; t <= n; t++){
		int l = 0, r = 0;
		rep(i, n) {
			if (i <= t)	l += w[i];
			else r += w[i];
		}
		ans = min(ans, abs(l - r));
	}
	printf("%d\n", ans);
	return 0;
}