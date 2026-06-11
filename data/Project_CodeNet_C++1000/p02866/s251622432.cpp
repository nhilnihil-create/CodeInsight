#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MOD = 998244353;

ll modpow(ll a, ll n, ll MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
	ll N;
	cin >> N;

	map<ll, ll> D;
	vector <ll> DD(N);
	ll maxD = 0;
	for (int ii = 0; ii < N; ++ii){
		ll tmp;
		cin >> tmp;
		D[tmp]++;
		DD[ii] = tmp;
		maxD = max(maxD, tmp);
	}

	bool ok = true;
	if( (DD[0]!=0) ) {
		ok = false;
	}
	for (int ii = 1; ii < N; ++ii){
		if (DD[ii] == 0){
			ok = false;
		}
	}
	if (!ok){
		cout << 0 << "\n";
		return 0;
	}

	ll ans = 1;
	ll prev = 1;
	for (int ii = 0; ii <= maxD; ++ii){
		if (D[ii] == 0){
			ans = 0;
			break;
		} else {
			ans = (ans * modpow(prev, D[ii], MOD)) % MOD;
			prev = D[ii];
		}
	}

	cout << ans << "\n";

	return 0;
}
