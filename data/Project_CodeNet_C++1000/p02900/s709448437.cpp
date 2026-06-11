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

	ll a, b; cin >> a >> b;

	vector<pair<long long, long long>> a_prime;  // a^x ならば { a, x }
	vector<pair<long long, long long>> b_prime;  // a^x ならば { a, x }
	a_prime = prime_factorize(a);
	b_prime = prime_factorize(b);

	map<int, int> mp;
	for (auto u : a_prime) {
		mp[u.first]++;
	}
	for (auto u : b_prime) {
		mp[u.first]++;
	}
	int ans = 0;
	for (auto u : mp) {
		if (2 <= u.second)ans++;
	}
	cout << ans + 1 << endl;
	return 0;
}