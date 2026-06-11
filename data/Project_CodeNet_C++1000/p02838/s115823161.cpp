#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;

ll mypow(ll x, ll n) {
        ll ans = 1;
        while(n) {
                if(n & 1) ans = (ans * x) % MOD;
                x = (x * x) % MOD;
                n>>=1;
        }
        return ans;
}

int main(int, char**) {
	vector<ll> b(65, 0);
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		ll a; cin >> a;
		for (int j=0; j<65; j++) {
			if (a & (1LL<<j)) b[j]++;
		}
	}
	ll ans = 0;
	for (int i=0; i<64; i++) {
		ll def = (mypow(2, i) * b[i]%MOD * (n - b[i])%MOD) % MOD;
		ans = (ans + def) % MOD;
	}
	cout << ans << endl;
	return 0;
}