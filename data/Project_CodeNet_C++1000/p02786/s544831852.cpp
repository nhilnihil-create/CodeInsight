#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int get_exp2(ll n) {
	
	ll a = 1;
	ll b = 0;
	while (true) {
		if (a <= n && n < a * 2) break;
		a *= 2;
		b += 1;
	}

	return b;

}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll h; cin >> h;
	int n = get_exp2(h);
	ll ans = 0;
	ll j = 1;
	rep(i, n + 1) {
		ans += j;
		j *= 2;
	}
	
	cout << ans << endl;
	return 0;
}
