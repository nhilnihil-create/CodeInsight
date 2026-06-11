#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

ll md = (ll)1e9 + 7;

int main()
{
	ll N;
	cin >> N;
	int width = (int)1e6;

	ll ans = (ll)1e12+100;
	for (int i = 1; i <= width; ++i) {
		if (N % i == 0) {
			ll cnt = i + (N / i) - 2;
			ans = min(ans, cnt);
		}
	}

	cout << ans << endl;
	return 0;
}
