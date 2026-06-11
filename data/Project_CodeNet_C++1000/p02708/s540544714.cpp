#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
#define rrep(i, j, n) for(size_t i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll n, k; cin >> n >> k;

	ll ans = 0;
	rep(i, k, n + 2) {
		ll mn = (ll)(i - 1) * i / 2;
		ll mx = (ll)(2 * n - i + 1) * i / 2;
		ans = (ans + mx - mn + 1) % MOD;
	}
	cout << ans;
	return 0;

}
