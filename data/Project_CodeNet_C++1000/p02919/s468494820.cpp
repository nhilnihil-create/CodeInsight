
// E - Second Sum

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int P[100000];
int pos[100001];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> P[i];
		pos[P[i]] = i;
	}

	ll ans = 0;
	multiset<int> pos_set;

	pos_set.insert(-1);
	pos_set.insert(-1);
	pos_set.insert(N);
	pos_set.insert(N);

	for (int i=N; i>=1; i--) {
		int k = pos[i];
		pos_set.insert(k);
		auto itr = pos_set.lower_bound(k);

		auto itr_l = itr;
		itr_l--;
		ll l1 = *itr_l;
		itr_l--;
		ll l2 = *itr_l;

		auto itr_r = itr;
		itr_r++;
		ll r1 = *itr_r;
		itr_r++;
		ll r2 = *itr_r;

		//cout << "X=" << i << " " << l2 << " " << l1 << " " << k << " " << r1 << " " << r2 << endl; // **** debug ****

		ans += i * ((l1 - l2) * (r1 - k) + (r2 - r1) * (k - l1));
	}

	cout << ans << endl;

	return 0;
}