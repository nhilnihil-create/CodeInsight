#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

const int MOD = 1000000007;

int main()
{
	ll n, k;
	cin >> n >> k;
	ll ret = 0;

	for (ll i = k; i <= n + 1; ++i)
	{
		ll first = i * (i - 1) / 2;
		ll last = (n * 2 - i + 1) * i / 2;
		ll add = last - first + 1;
		ret = (ret + add) % MOD;
 	}

	cout << ret << endl;
	return 0;
}