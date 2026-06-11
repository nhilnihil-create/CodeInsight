#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll n, ans = 0;
	cin >> n;
	rep(i,n)rep(j,n)rep(k,n) {
		ll g = 0;
		g = __gcd(i+1, j+1);
		ans += __gcd(g, k+1);
	}
	cout << ans << endl;
	return 0;
}
