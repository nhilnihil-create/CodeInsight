
// B - Counting of Trees

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 998244353;

ll mod_pow(ll a, ll n, ll mod) {
	ll result = 1;
	while (n > 0) {
		if (n & 1) result = result * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return result;
}

int D[100000];

int main() {
	int N;
	cin >> N;

	unordered_map<int, int> cnt;
	int max_D = -1;
	for (int i=0; i<N; i++) {
		cin >> D[i];
		cnt[D[i]]++;
		max_D = max(max_D, D[i]);
	}

	if (D[0] != 0 || cnt[0] > 1) {
		cout << 0 << endl;
		return 0;
	}

	ll ans = 1;

	for (int i=1; i<=max_D; i++) {
		if (cnt[i] == 0) {
			ans = 0;
			break;
		}

		ans = ans * mod_pow(cnt[i-1], cnt[i], MOD) % MOD;
	}

	cout << ans << endl;

	return 0;
}