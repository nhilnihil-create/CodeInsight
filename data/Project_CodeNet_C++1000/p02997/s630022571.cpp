#include <bits/stdc++.h>
typedef long long int LL;
using namespace std;

// 插入此處

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, K; cin >> N >> K;
	vector<pair<int, int>> v;
	for (int i = 2; i <= N; ++i) {
		v.push_back(make_pair(1, i));
	}
	K = (N-1)*(N-2)/2-K;
	for (int i = 2; i <= N; ++i) {
		for (int j = i+1; j <= N; ++j) {
			if (K) {
				v.push_back(make_pair(i, j));
				--K;
			}
		}
	}
	if (K) {
		cout << -1 << endl;
	} else {
		cout << v.size() << endl;
		for (auto x : v) {
			cout << x.first << ' ' << x.second << endl;
		}
	}
	return 0;
}
