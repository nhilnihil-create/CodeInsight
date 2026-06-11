#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;
#define vsort(a) sort(a.begin(),a.end(),greater<int>());

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<int> r(a), g(b), t(c);
	rep(i, a) cin >> r[i];
	rep(i, b) cin >> g[i];
	rep(i, c) cin >> t[i];
	vsort(r);
	vsort(g);
	rep(i, x) {
		if (r.size() == 0) break;
		t.push_back(r[0]);
		r.erase(r.begin());
	}
	rep(i, y) {
		if (g.size() == 0) break;
		t.push_back(g[0]);
		g.erase(g.begin());
	}
	
	vsort(t);
	ll sum = 0;
	rep(i,x + y) sum += t[i];
	cout << sum << endl;


	return 0;
}
