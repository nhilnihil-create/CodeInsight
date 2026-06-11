#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)
#define COS 2000005

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<bool> b(COS,false);
	ll i, j;
	ll ans = 0;

	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	rep(i, n - 1) {
		if (b[a[i]] == true)continue;
		if (a[i] == a[i + 1]) {
			b[a[i]] = true;
			//continue;
		}
		for (j = 2; j < a[n - 1] / a[i] + 1; j++) {
			b[j * a[i]] = true;
		}
	}
	rep(i, n) {
		if (b[a[i]] == false)ans++;
	}
	cout << ans << endl;




	return 0;
}
