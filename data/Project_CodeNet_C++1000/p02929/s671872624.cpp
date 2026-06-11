#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
char str[200005];
int main() {
	int n;
	scanf("%d%s", &n, str);
	int l = 0;
	const ll MOD = 1e9 + 7;
	ll ans = 1;
	for (int i = 0; i < 2 * n; ++i) {
		int col = (str[i] == 'W');
		col ^= (l & 1);
		if (col == 1) {
			if (!l) {
				printf("0\n");
				return 0;
			}
			ans = ans * l % MOD;
			--l;
		} else {
			++l;
		}
	}
	if (l > 0) ans = 0;
	for (int i = 1; i <= n; ++i) ans = ans * i % MOD;
	printf("%lld\n", ans);
}
