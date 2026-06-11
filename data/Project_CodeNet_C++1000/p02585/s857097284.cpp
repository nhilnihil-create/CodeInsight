#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
ll INF = 1LL << 60;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> P(N), C(N);
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		P[i]--;
	}
	for (int i = 0; i < N; i++) cin >> C[i];
	
	ll ans = -INF;

	for (int i = 0; i < N; i++) {
		int v = i;
		ll cycle_sum = 0;
		int cycle_cnt = 0;

		while (true) {
			cycle_cnt++;
			cycle_sum += C[v];
			v = P[v];
			if (v == i) break;
		}

		ll remainder = 0;
		int cnt = 0;

		while (true) {
			cnt++;
			remainder += C[v];

			if (cnt > K) break;
			
			int roop = (K - cnt) / cycle_cnt;
			ll score = remainder + max(0LL, cycle_sum) * roop;
			ans = max(ans, score);

			v = P[v];
			if (v == i) break;
		}
	}

	cout << ans << endl;

	return 0;
}