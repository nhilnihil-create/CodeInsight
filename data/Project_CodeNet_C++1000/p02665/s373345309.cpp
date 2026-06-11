
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[100001];
ll usable_non_leaf_nodes[100001];
ll max_non_leaf_nodes[100001];

int main() {
	int N;
	cin >> N;
	cin >> A[0];

	if (N == 0) {
		if (A[0] == 1) {
			cout << 1 << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
	} else if (A[0] > 0) {
		cout << -1 << endl;
		return 0;
	}

	usable_non_leaf_nodes[0] = 1;
	for (int i=1; i<N; i++) {
		cin >> A[i];
		usable_non_leaf_nodes[i] = min(usable_non_leaf_nodes[i-1] * 2 - A[i], (ll)1e18);
		if (usable_non_leaf_nodes[i] <= 0) {
			cout << -1 << endl;
			return 0;
		}
	}

	ll usable_N_leaves = usable_non_leaf_nodes[N-1] * 2;

	cin >> A[N];

	if (usable_N_leaves < A[N]) {
		cout << -1 << endl;
		return 0;
	}

	ll ans = A[N];
	max_non_leaf_nodes[N] = 0;
	for (int i=N-1; i>=0; i--) {
		max_non_leaf_nodes[i] = min(usable_non_leaf_nodes[i], max_non_leaf_nodes[i+1] + A[i+1]);
		ans += max_non_leaf_nodes[i] + A[i];
	}

	cout << ans << endl;

	return 0;
}