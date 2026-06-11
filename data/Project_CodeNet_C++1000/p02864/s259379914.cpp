#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int N = 310;
const ll inf = 1e15;
ll f[N][N];int n, k, h[N];
void mnm(ll &a, ll b) { a = min(a, b); }
int aug(int l, int r) {
	if (l >= r) return 0;
	return r - l;
}
int main() {
	//Read
	cin >> n >> k; for (int i = 1; i <= n; ++i) cin >> h[i];
	h[0] = h[n + 1] = 0;
	//Algo
	for (int i = 0; i <= n+1; ++i)
		fill(f[i] + 0, f[i] + k + 1, inf);
	f[0][0] = 0;
	for (int i=0; i<=n; ++i)
		for (int j=0; j<=k; ++j)
			if (f[i][j] < inf) {
				//mnm(f[i + 1][j], f[i][j] + aug(h[i], h[i + 1]));
				for (int bian = 0; i + bian + 1 <= n + 1 && j + bian <= k; ++bian) {
					mnm(f[i + bian + 1][j+bian], f[i][j] + aug(h[i], h[i + bian + 1]));
				}
			}
	ll ans = inf;
	for (int j = 0; j <= k; ++j)
		mnm(ans, f[n + 1][j]);
	cout << ans << endl;
}