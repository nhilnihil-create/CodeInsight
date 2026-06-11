#define rep(i, n) for(int i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll a,b,v,w,t;
	cin >> a >> v;
	cin >> b >> w;
	cin >> t;

	ll d = abs(a-b);
	ll u = v-w;

	bool ans = false;

	if (u>0) {
		if (u*t>=d) ans = true;
	}

	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
