#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define cint(a) int a; cin >> a;
#define cstr(str) string str; cin >> str;


using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll comb(ll n, ll r) {
	ll ans = 1;
	rep(i, r) {
		ans *= (n - i);
	}
	rep(i, r) {
		ans /= (i + 1);
	}
	return ans;
}



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	ll ans;
	ll sum = 0;
	cin >> n;
	vector<ll> a(n + 1);
	vector<ll> b(n);
	ll in;
	rep(i, n) {
		cin >> b[i];
		a[b[i]] += 1;
	}
	rep(i, n) sum += comb(a[i+1],2);
	rep(i, n) {
		ans = sum - comb(a[b[i]], 2) + comb(a[b[i]] - 1,2);
		cout << ans << endl;
	}
	return 0;
}
