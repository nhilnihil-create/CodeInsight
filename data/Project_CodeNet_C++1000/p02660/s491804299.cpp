#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<long long, long long> > prime_factorize(long long N) {
	vector<pair<long long, long long> > res;
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0; // 指数

		 // 割れる限り割り続ける
		while (N % a == 0) {
			++ex;
			N /= a;
		}

		// その結果を push
		res.push_back({ a, ex });
	}

	// 最後に残った数について
	if (N != 1) res.push_back({ N, 1 });
	return res;
}

int main() {

    ll n; cin >> n;
	vector<pair<long long, long long>> n_prime;  // a^x ならば { a, x }
	n_prime = prime_factorize(n);
	ll ans = 0;
	for (ll i = 0; i < n_prime.size() ; i++) {
		ll cnt = 1;
		ll tmp = n_prime[i].second;
		while (cnt <= tmp) {
			tmp -= cnt;
			cnt++;
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}