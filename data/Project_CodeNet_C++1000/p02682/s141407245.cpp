#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll a, b, c, k, ans = 0;
	cin >> a >> b >> c >> k;
	ll ad = k - a, bd = k - a - b;
	if (ad <= 0) ans = k;
	else if (bd <= 0) ans = a;
	else ans = a - bd;

	cout << ans << endl;
	return 0;
}
