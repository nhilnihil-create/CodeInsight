#include <bits/stdc++.h>
using namespace std;

int main() {
	int64_t k, q; cin >> k >> q;
	int64_t D[k]; for(int i = 0; i < k; ++i) cin >> D[i];
	while(q--) {
		int64_t n, x, m; cin >> n >> x >> m;
		int64_t d[k];
		int64_t cnteq = 0, sum = 0;
		for(int i = 0; i < k; ++i) {
			d[i] = D[i] % m;
			sum += d[i];
			if(d[i] == 0) ++cnteq;
		}
		int64_t loop = (n - 1) / k;
		cnteq *= loop;
		sum *= loop;
		int64_t mod = (n - 1) % k;
		for(int i = 0; i < mod; ++i) {
			sum += d[i];
			if(d[i] == 0) ++cnteq;
		}
		int64_t an = x + sum;
		cout << (n - 1) - cnteq - (an / m - x / m) << '\n';
	}
	return 0;
}