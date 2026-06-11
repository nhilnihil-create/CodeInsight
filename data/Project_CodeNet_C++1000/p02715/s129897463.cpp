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
	int n, k;
	cin >> n >> k;
	vector<long long> vec(k);
	ll ret = 0;
	for (int i=k; i>0; i--) {
		int c = k/i;
		ll now = mypow(c, n);
		for (int j=2; j*i<=k; j++) {
			now = (now - vec[j*i-1])%MOD;
			if (now<0) now += MOD;
		}
		vec[i-1] = now;
		ret = (ret + i%MOD * now%MOD)%MOD;
	}
	cout << ret << endl;
	return 0;
}
