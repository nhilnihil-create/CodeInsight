#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple

const int N = 1e6 + 10;
int n;
int p[N];

signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	sort(p, p + n);
	cout << p[n / 2] - p[n / 2 - 1] << "\n";
	return 0;
}
