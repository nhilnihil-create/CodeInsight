#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
//		freopen("in1.txt", "r", stdin);
//		freopen("in1.txt", "w", stdout);
	#endif
	ll x, k, d;
	cin >> x >> k >> d;
	ll tar1 = x % d;
	ll tar2;
	if (x < 0) tar2 = tar1 + d;
	else tar2 = tar1 - d;
	ll mn = abs(x/d);
	if (mn > k) {
		if (x < 0) cout << abs(x + k*d) << '\n';
		else cout << abs(x - k*d) << '\n';
		return 0;
	}
	ll diff = k - mn;
	cout << abs(((diff&1) ? tar2 : tar1)) << '\n';
}