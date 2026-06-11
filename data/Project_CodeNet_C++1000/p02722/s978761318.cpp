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

vector<ll> div(ll n) {
	vector<ll> res;
	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	auto mp = div(n);
	ll ans = 0;
	for (auto& c : mp) {
		if (c == 1) continue;
		ll tmp = n;
		ll now = c;
		while (tmp % now == 0) tmp /= now;
		tmp %= now;
		if (tmp == 1) ans++;
	}
	ans += div(n - 1).size() - 1;
	printf("%lld\n", ans);
	return 0;
}
