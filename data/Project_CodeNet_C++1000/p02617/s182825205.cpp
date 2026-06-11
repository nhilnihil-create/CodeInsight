#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef LOCAL
		freopen("in3.txt", "r", stdin);
//		freopen("ou1.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	ll ans = 0;
	for (ll i=1; i<n; i++) {
		ll x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		ans += i*(n-i+1);
		ans -= x*(n-y+1);
	}
	ans += n;
	cout << ans;
}