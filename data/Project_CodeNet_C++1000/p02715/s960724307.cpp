#include<bits/stdc++.h>
#define int long long
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define puts(x) cout << x << "\n"
constexpr int mod = 1000000007;
using namespace std;
int n, k, a[123456], ans;
int f1(int a, int p) {
	if (p == 1)return a;
	if (p % 2)return f1(a, p - 1) * a % mod;
	else return f1(a * a % mod, p / 2) % mod;
}
signed main() {
	cin >> n >> k;
	for1(i, k) a[i] = ((i == 1 || k / i != k / (i - 1)) ? f1(k / i, n) : a[i - 1]);
	for (int i = k; i >= 2; i--)for1(j, sqrt(i)) if (i%j == 0) {
		a[j] -= a[i]; if (a[j] < 0)a[j] += mod;
		if (j > 1 && j*j != i) { a[i / j] -= a[i]; if (a[i / j] < 0)a[i / j] += mod; }
	}
	for1(i, k) { ans += a[i] * i; ans %= mod; }
	puts(ans);
}