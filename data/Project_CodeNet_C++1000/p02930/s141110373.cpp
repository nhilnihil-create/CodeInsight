#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)

int d[514];
int n;
signed main() {
	cin >> n;
	rep(i, n - 1) {
		d[i] = log2((i + 1) & (-i - 1)) + 1;
	}
	rep(i, n - 1) {
		rep(j, n - i - 2) {
			printf("%lld ", d[j]);
		}
		printf("%lld\n", d[n - i - 2]);
	}
}
