#include <bits/stdc++.h>
#include "atcoder/all"
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
 
using namespace std;
using namespace atcoder;
using ll = long long;
 
int main() {
	int n, q;
	cin >> n >> q;
	dsu d(n);
	rep(i, q) {
		bool t;
		int a, b;
		cin >> t >> a >> b;
		if (t) {
			bool s;
			s = d.same(a, b);
			cout << (s ? 1 : 0) << endl;
		}
		else {
			d.merge(a, b);
		}
	}
	return 0;
}