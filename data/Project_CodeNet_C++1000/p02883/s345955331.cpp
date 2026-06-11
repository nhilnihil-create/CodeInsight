#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n), f(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> f[i];
	sort(a.begin(), a.end());
	sort(f.rbegin(), f.rend());
	ll l = -1, r = 1e12;
	while (r - l > 1) {
		ll c = (l + r) / 2;
		bool ok = [&] {
			ll s = 0;
			rep(i, n) {
				s += max(0LL, a[i] - c / f[i]);
			}
			return s <= k;
		}();
		if (ok) r = c;
		else l = c;
	}
	printf("%lld\n", r);
	return 0;
}
