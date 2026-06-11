#include <bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll a, b, n, ans = 0;
	cin >> a >> b >> n;
	if (n >=  b) n = b - 1;
	ans = (a*n) / b - n / b;
	cout << ans << endl;
	return 0;
}
