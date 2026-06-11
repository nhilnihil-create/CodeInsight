#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
bool used[55];
ll x[55], y[55];
int n;
ll p, q;
void dfs(int i) {
	if (used[i]) return;
	used[i] = true;
	for (int j = 0; j < n; ++j) {
		if ((x[i] - x[j] == p && y[i] - y[j] == q) ||
			(x[j] - x[i] == p && y[j] - y[i] == q)) {
			dfs(j);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%lld%lld", &x[i], &y[i]);
	int ans = n;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			p = x[j] - x[i];
			q = y[j] - y[i];
			int v = 0;
			fill(used, used + n, false);
			for (int k = 0; k < n; ++k) {
				if (used[k]) continue;
				dfs(k);
				++v;
			}
			ans = min(ans, v);
		}
	printf("%d\n", ans);
}
