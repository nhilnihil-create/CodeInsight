#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N, ans = INT_MAX;
	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	vector<pair<int, int>> xy(N);
	for (pair<int, int>& i : xy) cin >> i.first >> i.second;
	sort(xy.begin(), xy.end());
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int a = 0;
			for (int k = 0; k < N - 1; ++k) {
				int l;
				for (l = k + 1; l < N; ++l) {
					if (xy[i].first - xy[j].first == xy[k].first - xy[l].first && xy[i].second - xy[j].second == xy[k].second - xy[l].second) break;
				}
				if (N != l) ++a;
			}
			ans = min(N - a, ans);
		}
	}
	cout << ans;
}