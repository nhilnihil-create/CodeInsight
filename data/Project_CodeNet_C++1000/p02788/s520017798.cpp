#include <bits/stdc++.h>
using namespace std;

const int nm = 2e5;
int n, d, a, l[nm];long long ans = 0;
pair<int, int> m[nm];

//bit
long long bit[nm + 1];
void add(int i, int x) {
	i++;
	for (int j = i; j <= nm; j += j & -j)
		bit[j] += x;
}
long long sum(int i) {
	long long rv = 0;
	for (int j = i; j > 0; j -= j & -j)
		rv += bit[j];
	return rv;
}
long long sum(int l, int r) {
	return sum(r) - sum(l);
}

int main() {
	cin >> n >> d >> a;
	for (int i = 0, x, h; i < n; i++) {
		cin >> x >> h;
		h = (h + a - 1) / a;
		m[i] = make_pair(x, h);
	}
	sort(m, m + n);
	for (int i = 0, j = 0; i < n; i++) {
		while (m[j].first < m[i].first - 2 * d)
			j++;
		l[i] = j;
	}
	for (int i = 0; i < n; i++) {
		long long r = m[i].second-sum(l[i], i);
		if (r >0) {
			ans += r;
			add(i,r);
		}
	}
	cout << ans << endl;
}
