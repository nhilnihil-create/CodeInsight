#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();
const int MOD = 1000000007;

ll modpow(ll x, ll n) {
        ll ans = 1;
        while(n) {
                if(n & 1) ans = (ans * x) % MOD;
                x = (x * x) % MOD;
                n>>=1;
        }
        return ans;
}

ll COM(int n, int k) {
	ll ret = 1;
	ll div = 1;
	for (int i=0; i<k; i++) {
		ret = (ret * (n - i)%MOD)%MOD;
		div = (div * (i + 1)) % MOD;
	}
	div = modpow(div, MOD-2)%MOD;
	return (ret * div)%MOD;
}

int main(int, char**) {
	ll n, a, b;
	cin >> n >> a >> b;
	ll ret = modpow(2, n) - 1;
	ret += MOD - COM(n, a);
	ret %= MOD;
	ret += MOD - COM(n, b);
	ret %= MOD;

	cout << ret << endl;
	return 0;
}
