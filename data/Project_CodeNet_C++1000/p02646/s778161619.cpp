#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
//using mint = modint;
const int mod = 1000000007;
const double PI = acos(-1);

int main()
{
	ll a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;
	ll xa = a;
	ll xb = b;
	if (xa < xb) {
		xa = a + v * t;
		xb = b + w * t;
		if (xb <= xa) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else {
		xa = a - v * t;
		xb = b - w * t;
		if (xa <= xb) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}
