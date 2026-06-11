#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	ll n, k; cin >> n >> k;
	int* a = new int[n];
	rep(i, 0, n) cin >> a[i];

	ll ans = 0;
	rep(i, 0, n) {
		ll cnt1 = 0;
		ll cnt2 = 0;
		rep(j, 0, i) if (a[i] > a[j]) ++cnt1;
		rep(j, i, n) if (a[i] > a[j]) ++cnt2;
		ans = (ans + k * cnt2 % MOD + k * (k - 1) / 2 % MOD * (cnt1 + cnt2) % MOD) % MOD;
	}
	cout << ans << '\n';

	delete[] a;
	return 0;
}
