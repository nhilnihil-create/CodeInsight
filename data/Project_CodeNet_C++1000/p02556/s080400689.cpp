#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int n;
	cin >> n;
	vector<ll> z(n),w(n);
	rep(i,n) {
		int x,y;
		cin >> x >> y;
		z[i] = x + y;
		w[i] = x - y;
	}
	ll zmax=-4e18,zmin=4e18,wmax=-4e18,wmin=4e18;
	rep(i,n) {
		if (zmax < z[i]) zmax = z[i];
		if (zmin > z[i]) zmin = z[i];
		if (wmax < w[i]) wmax = w[i];
		if (wmin > w[i]) wmin = w[i];
	}
	cout << max(zmax - zmin, wmax - wmin) << endl;
	return 0;
}
