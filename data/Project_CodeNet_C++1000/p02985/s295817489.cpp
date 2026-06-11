#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple

const int N = 1.1e5;
const int M = 1e9 + 7;

int n;
int k;
int d[N];
int f[N];
int r[N];

signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	f[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = f[i - 1] * i % M;
	}
	r[N - 1] = 146087799;
	for (int i = N - 2; i >= 0; --i) {
		r[i] = r[i + 1] * (i + 1) % M;
	}

	cin >> n >> k;
	if (n == 1) {
		cout << k << "\n";
		return 0;
	}
	for (int v, u, i = 0; i < n - 1; ++i) {
		cin >> v >> u;
		++d[--v];
		++d[--u];
	}

	int ans = 1;
	for (int i = 0; i < n; ++i) {
		if (d[i] > k - 1) {
			ans = 0;
			break;
		}
		(ans *= f[k - 2]) %= M;
		(ans *= r[k - 1 - d[i]]) %= M;
	}

	(ans *= k * (k - 1)) %= M;
	cout << ans << "\n";
	return 0;
}
