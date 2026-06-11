#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	ll n, k;
	cin >> n >> k;
	V<ll> a(n);
	ll sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	
	V<ll> div(0);
	rep1(i, sqrt(sum)) {
		if (sum % i)continue;
		div.push_back(i);
		if (sum / i != i)div.push_back(sum / i);
	}

	sort(all(div), greater<ll>());

	ll ans = 1;

	for(auto t:div) {

		V<ll> d(n);
		ll ls = 0, rs = 0, cnt = LINF;

		rep(j, n) {
			d[j] = a[j] % t;
			rs += t - d[j];
		}

		sort(all(d));

		rep(j, n) {
			ls += d[j];
			rs -= t - d[j];
			cnt = min(cnt, max(ls, rs));
		}

		if (cnt <= k) {
			ans = t;
			break;
		}
	}

	cout << ans << endl;

}