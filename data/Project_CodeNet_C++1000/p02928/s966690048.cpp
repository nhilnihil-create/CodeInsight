#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll N, K;
	cin >> N >> K;
	ll A[N];
	for(int i = 0; i < N; i++) cin >> A[i];

	ll inv[N], rinv[N];
	for(int i = 0; i < N; i++) {
		inv[i] = 0;
		for(int j = 0; j < i; j++) {
			if(A[j] > A[i]) inv[i]++;
		}
	}
	for(int i = N - 1; i >= 0; i--) {
		rinv[i] = 0;
		for(int j = N - 1; j > i; j--) {
			if(A[j] > A[i]) rinv[i]++;
		}
	}
	ll ans = 0;
	for(int i = 0; i < N; i++) {
		ans += (inv[i] * (((K + K * K) / 2) % mod)) % mod;
		ans %= mod;
		K--;

		ans += (rinv[i] * (((K + K * K) / 2) % mod)) % mod;
		ans %= mod;
		K++;
	}
	cout << ans << "\n";
	return 0;
}