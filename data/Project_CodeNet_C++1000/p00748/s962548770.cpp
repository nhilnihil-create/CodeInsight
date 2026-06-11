#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
const int W = 1e6;
signed main() {
	vector<int>c(1, 0), odd(1, 0);
	for (int i = 1; i*(i + 1)*(i + 2) / 6 < W; i++) {
		c.push_back(i*(i + 1)*(i + 2) / 6);
		if (c[i] & 1)odd.push_back(c[i]);
	}
	vector<int>v1(W, INF), v2(W, INF); v1[0] = v2[0] = 0;
	rep(i, 1, c.size()) {
		rep(j, c[i], W) {
			v1[j] = min(v1[j], v1[j - c[i]] + 1);
		}
	}
	rep(i, 1, odd.size()) {
		rep(j, odd[i], W) {
			v2[j] = min(v2[j], v2[j - odd[i]] + 1);
		}
	}

	int n;
	while (cin >> n, n) {
		cout << v1[n] << " " << v2[n] << endl;
	}
	return 0;
}