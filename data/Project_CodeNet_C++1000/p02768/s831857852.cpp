#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll fastPower (ll a, ll n) {
	if (n == 0) return 1 % MOD;
    ll ans = fastPower(a, n / 2);

    ans = (ans * ans) % MOD;
    
    if (n % 2 == 1) {
    	ans = (ans * a) % MOD;
    }
    return ans;
}

ll invmod (ll x) {
	return fastPower(x, MOD-2);
}

ll comb (ll a, ll n) {
	ll ans = 1;
	for(ll i = n; i >= n - a + 1; i--){
		ans *= i;
		ans %= MOD;
	}
	for(ll i = 1; i <= a; i++){
		ans *= invmod(i);
		ans %= MOD;
	}
	return ans;
}

ll sub(ll a, ll b) {
	ll ans = a - b;
	if (ans < 0) ans += MOD;
	return ans % MOD;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = fastPower(2, n);
    ll tosub = 1 + comb(a, n) + comb(b, n);
    tosub %= MOD;
    ans = sub(ans, tosub);

    cout << ans << endl ;
    return 0;

}
