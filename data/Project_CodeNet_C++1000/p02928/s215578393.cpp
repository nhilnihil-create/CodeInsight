#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)


constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	rep(i, 0, n) cin >> a[i];

	ll ans = 0;
	rep(i, 0, n) {
		ll cnt = 0;
		rep(j, i + 1, n) if (a[i] > a[j]) ++cnt;
		ans += cnt * k;
		ans %= MOD;
	}

	rep(i, 0, n) {
		ll cnt = 0;
		rep(j, 0, n) if (a[i] > a[j]) ++cnt;
		ans += k * (k - 1) / 2 % MOD * cnt % MOD;
		ans %= MOD;
	}
	cout << ans;

	return 0;
}