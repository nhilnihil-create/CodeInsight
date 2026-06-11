#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> p(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	long long ans = LLONG_MIN;
	for (int i = 0; i < n; i++) {
		vector<int> cyc(n, -1);
		long long sum = 0;
		int cur = i;
		for (int i = 0; i < k; i++) {
			if (cyc[cur] >= 0 && 2 * n <= k) {
				long long prefix = 0, start = cur;
				do {
					prefix += c[cur];
					ans = max(sum + prefix, ans);
					cur = p[cur];
				} while (cur != start);
				int cycle_size = i - cyc[cur], moves_left = k - i;
				long long take = 1LL * (moves_left/cycle_size - 1) * prefix;
				prefix = 0;
				for (int i = 0; i < moves_left % cycle_size + cycle_size; i++) {
					prefix += c[cur];
					ans = max(sum + take + prefix, ans);
					cur = p[cur];
				}
				break;
			}
			sum += c[cur];
			ans = max(ans, sum);
			cyc[cur] = i;
			cur = p[cur];
		}
	}
	cout << ans << '\n';
}
