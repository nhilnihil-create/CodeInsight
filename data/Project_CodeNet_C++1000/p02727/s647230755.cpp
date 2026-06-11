#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<ll, int> pli;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<pli> v;
	rep(i,a) {
		ll t;
		cin >> t;
		v.push_back(pli(t, 0));
	}
	rep(i,b) {
		ll t;
		cin >> t;
		v.push_back(pli(t, 1));
	}
	rep(i,c) {
		ll t;
		cin >> t;
		v.push_back(pli(t, 2));
	}
	sort(ALL(v), greater<>());
	int cnt0 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	int i = 0;
	ll ans = 0;
	while (cnt0 + cnt1 + cnt2 < x + y) {
		auto p = v[i++];
		if (cnt0 < x && p.second == 0) {
			ans += p.first;
			cnt0++;
		} else if (cnt1 < y && p.second == 1) {
			ans += p.first;
			cnt1++;
		} else if (p.second == 2) {
			ans += p.first;
			cnt2++;
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}