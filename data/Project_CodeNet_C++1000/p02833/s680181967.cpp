#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
ll g1(ll n, ll p)
{
	if (n == 0)	return 0;
	return n / p + g1(n / p, p);
}
ll g2(ll n, ll p)
{
	if (n % 2 == 1) {
		return g1(n, p) - g2(n - 1, p);
	}
	ll ret = g1(n / 2, p);
	if (p == 2)	ret += n / 2;
	return ret;
}
int main()
{
	ll n = 0;
	cin >> n;
	if (n % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = min(g2(n, 2), g2(n, 5));
	cout << ans << endl;

	return 0;
}