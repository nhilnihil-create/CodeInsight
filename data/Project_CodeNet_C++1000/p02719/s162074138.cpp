#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	ll a = n / k;
	ll ans;
	ans = n - a * k;
	ans = min(ans, k - ans);
	cout << ans << endl;
	return 0;
}
