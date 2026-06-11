#include <bits/stdc++.h>
using namespace std;
#define int long long
void read (int &x) {
	char ch = getchar(); x = 0;
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
} const int N = 3038, mod = 998244353;
int n, s, res, inv, a[N], f[N];    
int Pow (int x, int y) {
	int tmp = 1;
	while (y) {
		if (y & 1) tmp = tmp * x % mod;
		x = x * x % mod, y >>= 1;
	} return tmp;
}
signed main() {
	read (n), read (s); 
	for (int i = 1; i <= n; ++i) read (a[i]);
	f[0] = Pow (2, n); inv = Pow (2, mod - 2);
	for (int i = 1; i <= n; ++i) {
		for (int j = s; j >= a[i]; --j)
			f[j] = (f[j] + f[j - a[i]] * inv) % mod;
	} return printf ("%lld\n", f[s]), 0;
}