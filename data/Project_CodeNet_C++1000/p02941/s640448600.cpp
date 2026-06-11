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
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	set<pair<int, int>> S;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
		S.insert({b[i], i});
	}
	auto no = [&]() {
		printf("-1\n");
		exit(0);
	};
	ll ans = 0;
	while (!S.empty()) {
		auto x = *S.rbegin();
		S.erase(x);
		int id = x.second;
		if (b[id] == a[id]) continue;
		if (b[id] < a[id]) no();
		int v = b[(id + n - 1) % n] + b[(id + 1) % n];
		if (b[id] <= v) no();
		if (a[id] >= v) {
			if ((b[id] - a[id]) % v) no();
			ans += (b[id] - a[id]) / v;
			b[id] = a[id];
		} else {
			int t = b[id] % v;
			ans += (b[id] - t) / v;
			b[id] = t;
			S.insert({b[id], id});
		}
	}
	printf("%lld\n", ans);
}
