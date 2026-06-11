#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	ll a, b;
	ll aa, bb;
	ll ans;
	cin >> a >> b;
	aa = (ll)a / 0.08;
	if (aa * 0.08 != a)aa++;
	bb = (ll)b / 0.1;
	if (bb * 0.1 != b)bb++;
	if (aa < bb) {
		while (1) {
			if ((ll)(bb * 0.08) < a)bb++;
			else if ((ll)(bb * 0.08) > a) {
				cout << -1 << endl;
				return 0;
			}
			else {
				ans = bb;
				break;
			}
			if ((ll)(bb * 0.1) != b) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	else {
		while (1) {
			if ((ll)(aa * 0.1) < b)aa++;
			else if ((ll)(aa * 0.1) > b) {
				cout << -1 << endl;
				return 0;
			}
			else {
				ans = aa;
				break;
			}
			if ((ll)(aa * 0.08) != a) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
