#include"bits/stdc++.h"
#include<cassert>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long inf = 1ll << 62;
typedef long double ld;
typedef pair<ld, int> P;
ld x[105], y[105];

signed main() {
	int n; cin >> n;
	rep(i, n)cin >> x[i] >> y[i];
	vector<P>V;
	rep(i, n) {
		if (x[i] == 0 && y[i] == 0)continue;
		ld theta = atan2(y[i], x[i]);
		V.push_back(P(theta, i));
	}
	sort(V.begin(), V.end());

	ld ans = 0;
	n = V.size();
	rep(i, n) {
		rep(j, n) {
			ld sx = 0, sy = 0;
			if (i<=j) {
				for (int k = i; k <= j; k++) {
					sx += x[V[k].second];
					sy += y[V[k].second];
				}
			}
			else {
				for (int l = i; l <= n + j; l++) {
					int k = l%n;
					sx += x[V[k].second];
					sy += y[V[k].second];
				}
			}
			ld res = sqrt(sx*sx + sy*sy);
			if (ans < res)ans = res;
		}
	}
	printf("%.13Lf\n", ans);
}