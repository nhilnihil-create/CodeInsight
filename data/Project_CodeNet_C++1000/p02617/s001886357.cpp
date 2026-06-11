#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
template <typename T> inline T read() {
	bool f = 1; T x = 0; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = !f;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	return f ? x : -x;
}
#define gi read<int>()
#define gl read<ll>()

const int N = 200000 + 5;
int n, u[N], v[N];
int main() {
	n = gi;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) ans += (ll)i * (i + 1) / 2;
	for (int i = 1; i < n; ++i) {
		int u = gi, v = gi;
		if (u > v) swap(u, v);
		ans -= (ll)u * (n - v + 1);
	}
	cout << ans << '\n';
	return 0;
}