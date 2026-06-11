#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
#define double ll

int main() {
	FASTIO
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (auto &i : a) {
		cin >> i;
	}

	auto f = [&](double m) -> bool {
		if(m == 0){
			ll u = 0;
			for(int i = 0 ; i < 1 ; i++){
				double x = a[i];
				ll r = 1;
				ll e = 0;
				while(x >= 1){
//					clog << x << ' ' << e << ' ' << r << endl;
					e += r;
//					clog << x << ' ' << e << ' ' << r << endl;
					r <<= 1;
					x /= 2;
				}
				u += e;
			}
			return u <= k;
		}
		ll u = 0;
		for (int i = 0; i < n; i++) {
			u += ((a[i] - 1) / m) ;

		}
		return u <= k;
	};
	double lo = 1, hi = 1e9;
	for (auto _ = 0; _ < 100; _++) {
		double mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << hi << endl;
}