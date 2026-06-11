#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

const int N = 5000;

int ii[N], cc[N], qu[N];
bool visited[N];

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int p; cin >> p, p--;
		ii[i] = p;
	}
	for (int i = 0; i < n; i++)
		cin >> cc[i];
	long long ans = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		fill(visited, visited + n, false);
		int cnt = 0;
		int i_ = i;
		while (!visited[i_]) {
			qu[cnt++] = i_;
			visited[i_] = true;
			i_ = ii[i_];
		}
		int m = 0;
		int i__ = i;
		while (i__ != i_) {
			m++;
			i__ = ii[i__];
		}
		if (k < m) {
			long long a = 0;
			for (int h = 0; h < k; h++)
				ans = max(ans, a += cc[qu[h]]);
		} else {
			long long a = 0;
			for (int h = 0; h < m; h++)
				ans = max(ans, a += cc[qu[h]]);
			long long b = 0;
			for (int h = m; h < cnt; h++)
				b += cc[qu[h]];
			if (b > 0) {
				long long b_ = 0;
				for (int h = m; h < cnt && h <= k; h++) {
					ans = max(ans, a + (k - m - (h - m)) / (cnt - m) * b + b_);
					b_ += cc[qu[h]];
				}
			} else {
				long long b_ = 0;
				for (int h = m; h < cnt && h <= k; h++) {
					if (h > 0)
						ans = max(ans, a + b_);
					b_ += cc[qu[h]];
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
