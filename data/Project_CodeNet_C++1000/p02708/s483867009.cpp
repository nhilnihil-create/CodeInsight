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
int main()
{
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	ll first, last;
	for (int i = k; i <= n + 1; ++i) {
		first = ll(i - 1) * ll(i) / ll(2);
		last = (ll(n) + ll(n + 1 - i))*ll(i) / ll(2);
		ans += last - first + 1;
		ans %= ll(MOD);
	}
	cout << ans << endl;
	return 0;
}