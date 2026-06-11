#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define ll long long
#define int long long
#define Size(v) (int)v.size()

using namespace std;
// using namespace __gnu_pbds;

const int nax = 5e6 + 5;
int fact[nax];
const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}
int square(ll x) {return mul(x, x);}
int binpow(ll a, ll b) {
	if (b == 0) return 1 % MOD;
	if (b % 2 == 0) return square(binpow(a, b/2)) % MOD;
	return a*(square(binpow(a, b/2))) % MOD;
}
void genfact(ll n) {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i % MOD;
}
int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}
int Ckn(int n, int k)
{
	if (k > n) return 0;
    return divide(fact[n], mul(fact[k], fact[n - k]));
}

void solve() {
	int x, y;
	cin >> x >> y;

	fact[0] = 1;

	for (int i = 1; i <= 5000000; ++i) fact[i] = (fact[i - 1] * i) % MOD;

	if ((x + y) % 3 != 0) {
		cout << 0;
		return;
	}

	int mn = (x + y) / 3;

	int m = x - mn;

	m = max(m, y - mn);

	cout << Ckn(mn, m);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	while (t--) 
		solve();
	return 0;
}