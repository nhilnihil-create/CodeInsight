#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	ll ans = 0;
	ll c = n - 1;
	for (ll i = 1; i * i <= n - 1; i++) {
		if (c % i == 0) {
			ans += 2;
			if (i * i == n - 1)ans--;
			if (i == 1)ans--;
		}
	}
	c++;
	for (ll i = 1; i * i <= n; i++) {
		c = n;
		if (c % i == 0) {
			if (i != 1) {
				while (c % i == 0) {
					c /= i;
				}
				if (c % i == 1)ans++;
			}
			c = n;
			ll k = c / i;
			//cout << c << " " << i << " " << k << "\n";
			if (k == i)continue;
			while (c % k == 0) {
				c /= k;
			}
			if (c % k == 1)ans++;
		}

	}
	cout << ans;
}