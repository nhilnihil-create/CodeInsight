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
char str[1000005];
int main() {
	int n;
	scanf("%d%s", &n, str);
	for (int i = 0; i < n; ++i) --str[i];
	auto f = [&](string s) {
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			int odd = (((n - 1) & i) == i);
			if (s[i] == '1') ret ^= odd;
		}
		return ret;
	};
	bool hasOne = false;
	for (int i = 0; i < n; ++i) hasOne |= str[i] == '1';
	if (hasOne) {
		string strpar(str);
		for (int i = 0; i < n; ++i) {
			if (str[i] == '2') strpar[i] = '0';
		}
		printf("%d\n", f(strpar));
	} else {
		string strpar(str);
		for (int i = 0; i < n; ++i) {
			if (str[i] == '2') strpar[i] = '1';
		}
		printf("%d\n", f(strpar) * 2);
	}
}
