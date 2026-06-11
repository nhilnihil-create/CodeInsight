#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	int mxp = -2e9, mxm = -2e9, mnp = 2e9, mnm = 2e9;
	rep(i, n) {
		int a,b;
		cin >> a >> b;
		mxp = max(mxp, a + b);
		mxm = max(mxm, a - b);
		mnp = min(mnp, a + b);
		mnm = min(mnm, a - b);
	}
	int ans = 0;
	ans = max(mxp - mnp, mxm - mnm);
	cout << ans << endl;

	return 0;
}
