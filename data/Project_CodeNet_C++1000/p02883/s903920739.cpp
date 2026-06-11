
// E - Gluttony

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int N;
ll K;
ll A[1000000];
ll F[1000000];

bool is_ok(ll k) {
	ll need = 0;
	for (int i=0; i<N; i++) {
		need += max(0LL, A[i] - k / F[i]);
	}
	//cout << "k=" << k << " need=" << need << endl; // **** debug ****
	return need <= K;
}

ll find_min_ok(ll lower, ll upper) {
	if (!is_ok(upper - 1)) return -1; // 存在しない

	ll ok = upper - 1;
	ll ng = lower - 1;

	while(ok - ng > 1) {
		ll trying = (ng + ok) / 2;

		if (is_ok(trying)) {
			ok = trying;
		} else {
			ng = trying;
		}
	}

	return ok;
}

int main() {
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	for (int i=0; i<N; i++) {
		cin >> F[i];
	}

	sort(A, A+N);
	sort(F, F+N, greater<ll>());

	ll ans = find_min_ok(0, 10000000000000LL);

	cout << ans << endl;

	return 0;
}