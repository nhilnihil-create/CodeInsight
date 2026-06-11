#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, a, b; cin >> n >> a >> b;
	ll c = a + b;
	ll quo = n / c;
	ll mod = n % c;
	ll ans;
	if (mod == 0) {
		ans = quo * a;
	}
	else if (mod <= a) {
		ans = quo * a + mod;
	}
	else {
		ans =  (quo)*a+a;
	}
	cout << ans << endl;
    return 0;
}
