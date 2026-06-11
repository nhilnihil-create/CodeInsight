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
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] /= 2;
	}
	int pk = -1;
	ll x = 1;
	for (int i = 0; i < n; ++i) {
		int k = 1;
		while (a[i] % (k << 1) == 0) k <<= 1;
		if (pk != -1 && pk != k) {
			printf("0\n");
			return 0;
		}
		pk = k;
		x = x * a[i] / __gcd(x, (ll)a[i]);
		if (x > m) {
			printf("0\n");
			return 0;
		}
	}
	int nums = m / x;
	int ans = (nums + 1) / 2;
	printf("%d\n", ans);
}
