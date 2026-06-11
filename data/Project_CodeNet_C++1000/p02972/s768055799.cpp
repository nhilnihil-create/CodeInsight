#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9+7, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;

ll arr[200001];
ll cnt[200001];
ll ans[200001];

vector< int64_t > divisor(int64_t n) {
	vector< int64_t > ret;
	for (int64_t i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return (ret);
}

int main() {
	cin >> N;
	rep(i, N) {
		cin >> arr[i + 1];
		cnt[i + 1] = 0;
	}
	ll count = 0;
	for (int i = N; i > 0; i--) {
		if ((arr[i] == 1) ^ (cnt[i] % 2 == 1)) {
			ans[i] = 1;
			count++;
			auto vec = divisor(i);
			rep(i, vec.size()) {
				cnt[vec[i]]++;
			}
		}
	}
	cout << count << endl;
	rep(i, N) {
		if (ans[i + 1] == 1) cout << i + 1 << " ";
	}
}
