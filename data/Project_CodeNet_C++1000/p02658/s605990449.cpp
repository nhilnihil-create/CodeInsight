#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int n;
	cin >> n;
	ll ans(1);
	ll m = pow(10, 18);
	bool f = true;
	rep(i, n) {
		ll k;
		cin >> k;
		if (k == 0) {
			cout << 0;
			return 0;
		}
		ll bans = ans;
		ans *= k;
		if (ans > m) {
			f = false;
		}
		if (bans>m/k) {
			f = false;
		}
	}
	if (f) {
		cout << ans;
	}
	else {
		cout << -1;
	}

	return 0;
}