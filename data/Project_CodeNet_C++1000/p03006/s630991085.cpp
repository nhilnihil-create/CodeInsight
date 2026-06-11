
// B - Picking Up

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int x[50], y[50];

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> x[i] >> y[i];
	}

	map<pair<int, int>, int> cnt;

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (i == j) continue;

			cnt[make_pair(x[j] - x[i], y[j] - y[i])]++;

		}
	}

	int max_cnt = 0;
	for (auto itr : cnt) {
		max_cnt = max(max_cnt, itr.second);
	}

	int ans = N - max_cnt;

	cout << ans << endl;

	return 0;
}