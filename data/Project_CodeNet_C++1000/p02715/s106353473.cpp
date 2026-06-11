#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int M = 1e9 + 7;

ll fast_pow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans = ans * a % M;
		b >>= 1;
		a = a * a % M;
	}
	return ans;
}

ll f(int n, int k, int x) {
	return fast_pow(k/x, n);
}

const int N = 2e5 + 7;
ll F[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;

	ll ans = 0;
	for(int i = k; i >= 1; --i) {
		ll aux = 0;
		aux = f(n, k, i);
		for(int j = i + i; j <= k; j += i) {
			aux = (aux -  F[j] + M)%M;
		}
		ans += aux * i % M;
		ans %= M;
		F[i] = aux;
	}
	cout << ans << '\n';
}