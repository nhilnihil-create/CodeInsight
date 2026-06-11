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
char str[200005];
int main() {
	int n, k, c;
	scanf("%d%d%d", &n, &k, &c);
	scanf("%s", str);
	vector<int> dp(n + 1), rdp(n + 2);
	int las = -1e9;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'o' && i > las + c) {
			las = i;
			dp[i + 1] = dp[i] + 1;
		} else {
			dp[i + 1] = dp[i];
		}
	}
	las = 1e9;
	for (int i = n - 1; i >= 0; --i) {
		if (str[i] == 'o' && i < las - c) {
			las = i;
			rdp[i + 1] = rdp[i + 2] + 1;
		} else {
			rdp[i + 1] = rdp[i + 2];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (dp[i - 1] + rdp[i + 1] < k) {
			printf("%d\n", i);
		}
	}
}
