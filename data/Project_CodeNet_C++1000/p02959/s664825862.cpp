#include "bits/stdc++.h"
using namespace std;

//49 
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n + 1);
	vector<ll> b(n);
	//vector<ll> val(n);
	for (int i = 0; i < n + 1; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	//sort(val.rbegin(),val.rend());
	//sort(b.rbegin(),b.rend());
	ll ans = 0;
    for (int i = 0; i < n; ++i) {
		if (a[i] <= b[i]) {
			ans += a[i];
			if (i + 1 <= n) {
				ans += min(b[i] - a[i],a[i + 1]);
				a[i + 1] -= b[i] - a[i];
				if (a[i + 1] < 0) {
					a[i + 1] = 0;
				}
			}
		}else {
			ans += b[i];
		}
	}
	//for (int i = 0; i < n; ++i) {
		//ans += 1LL * min(val[i],b[i]);
	    //if (i + 1 < n) val[i + 1] -=  (min(val[i],b[i]) - min(a[i],b[i]));
	//}
	cout << ans;
}
