#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	string s;
	cin >> n >> m >> s;
	vector<int> p;
	rep(i, n + 1) if (s[i] == '0') p.push_back(i);
	vector<int> ans;
	int now = n;
	while (now) {
		auto itr = lower_bound(all(p), now - m);
		if (itr == p.end()) {
			cout << -1 << endl;
			return 0;
		}
		if (*itr >= now) {
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(now - *itr);
		now = *itr;
	}
	int N = ans.size();
	for (int i = N - 1; i >= 0; i--) {
		if (i < N - 1) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
