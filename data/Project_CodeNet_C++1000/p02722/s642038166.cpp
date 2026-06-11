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

vector<ll> div(ll a) {
	vector<ll> ret;
	for (ll i = 1; i * i <= a; ++i) {
		if (a % i == 0) {
			ret.push_back(i);
			if (i * i != a) ret.push_back(a / i);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<ll> rec = div(n);
	int ans = 0;
	for (ll c : rec) {
		if (c == 1) continue;
		ll tmp = n;
		while (tmp % c == 0) tmp /= c;
		tmp %= c;
		if (tmp == 1) ans++;
	}
	ans += (int)div(n - 1).size() - 1;
	printf("%d\n", ans);
	return 0;
}
