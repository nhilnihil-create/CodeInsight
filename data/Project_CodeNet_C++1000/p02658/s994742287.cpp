#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)
#define LM 1000000000000000000

int main() {
	int n;
	ll ans = 1;
	int chk = 0;
	ll buf;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
		if (a[i] == 0)chk = 1;
	}
	if (chk == 0) {
		rep(i, n) {
			if (a[i] > LM / ans) {
				ans = -1;
				break;
			}
			ans *= a[i];
		}
	}
	else ans = 0;
	
	if (ans > LM)ans = -1;
	cout << ans << endl;
	return 0;
}