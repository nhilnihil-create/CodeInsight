#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) {
		cin >> a[i];
		ans ^= a[i];
	}
	ll cpy = ans;
	rep(i,n) {
		ans = cpy ^ a[i];
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}
