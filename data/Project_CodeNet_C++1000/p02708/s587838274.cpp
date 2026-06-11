#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll N, K;
	cin >> N >> K;

	ll ans = 0;
	for(int i = K; i <= N + 1; i++) {
		ans += (((i * (N + 1 - i)) % mod) + 1) % mod;
		ans %= mod;
	}
	cout << ans << "\n";
}