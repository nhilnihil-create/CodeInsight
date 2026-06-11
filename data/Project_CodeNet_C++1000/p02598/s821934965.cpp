#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

ll check(ll L, ll N, vector<ll> A) {
	ll ret = 0;
	for (int i=0; i<N; i++) {
		ret += (A[i] + L - 1)/L - 1;
	}
	return ret;
}

int main(int, char**) {
	ll n, k; cin >> n >> k;
	vector<ll> A(n);
	for (int i=0; i<n; i++) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll u = A[n - 1];
	ll d = 0;
	while (u - d > 1) {
		ll mid = (u + d) / 2;
		if (check(mid, n, A) <= k) u = mid;
		else d = mid;
	}
	cout << u << endl;

	return 0;
}