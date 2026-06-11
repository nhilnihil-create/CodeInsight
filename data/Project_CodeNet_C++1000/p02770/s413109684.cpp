#include <bits/stdc++.h>
using namespace std;

const int K = 5003;
int d[K];

int hmt(int n, int k, int i) {
	int dr = (--n) / k;
	if(n % k >= i)
		++dr;
	return dr;
}

int ffp(int n, int x, int m, int k) {
	int dr = 0;
	for(int i = 1; i <= k; ++i) {
		if(d[i] == 0)
			dr += hmt(n, k, i);
	}
	int sgn = x / m, gn = sgn, ns = x % m;
	for(int i = 1; i <= k; ++i) {
		long long tmp = d[i];
		tmp *= hmt(n, k, i);
		tmp += ns;
		ns = tmp % m;
		gn += tmp / m;
	}
	dr += gn - sgn;
	dr = n - 1 - dr;
	return dr;
}

int k, q, rd[K], n, x, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> q;
	for(int i = 1; i <= k; ++i)
		cin >> rd[i];
	for(int qi = 1; qi <= q; ++qi) {
		cin >> n >> x >> m;
		for(int i = 1; i <= k; ++i)
			d[i] = rd[i] % m;
		cout << ffp(n, x, m, k) << "\n";
	}
	cout << flush;
	return 0;
}
