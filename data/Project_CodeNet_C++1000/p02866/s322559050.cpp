#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 998244353;

ll lpow(int p, int q) {
	ll ans = 1;
	ll pp = p;
	while (q) {
		if (q % 2) {
			ans *= pp;
			ans %= MOD;
		}
		q /= 2;
		pp *= pp;
		pp %= MOD;
	}
	return ans;
}

int main() {

	int n;
	cin >> n;
	map<int, int> mp;
	int mx = 0;
	bool ng = false;
	rep(i, n) {
		int d;
		cin >> d;
		if (i == 0 && d != 0)ng = true;
		if (i > 0 && d == 0)ng = true;
		mp[d]++;
		mx = max(mx, d);
	}

	ll ans = 1;
	if (ng)ans *= 0;

	rep(i, mx) {
		ans *= lpow(mp[i], mp[i + 1]);
		ans %= MOD;
	}

	cout << ans << endl;

}