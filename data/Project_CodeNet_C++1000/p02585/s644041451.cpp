#include <iostream>
#include <vector>
using namespace std;
const long long INF = (1ull<<62) - 1;

int main() {
	long long n, k;
	cin >> n >> k;
	vector<long long> p(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	long long ans = -INF;
	for (int i = 0; i < n; i++) {
		vector<bool> f(n, false);
		int cycle;
		for (int j = 0, x = i; ; j++) {
			if (f[x] == true) {
				cycle = j;
				break;
			}
			f[x] = true;
			x = p[x];
		}
		if (k < cycle) {
			long long s = 0;
			for (int j = 0, x = i; j < k; j++) {
				s += c[x];
				ans = max(ans, s);
				x = p[x];
			}
		} else {
			long long s = 0;
			for (int j = 0, x = i; j < cycle; j++) {
				s += c[x];
				ans = max(ans, s);
				x = p[x];
			}
			s = s * (k / cycle - 1);
			int r = k % cycle + cycle;
			for (int j = 0, x = i; j < r; j++) {
				s += c[x];
				ans = max(ans, s);
				x = p[x];
			}
		}
	}
	cout << ans << endl;
	return 0;
}