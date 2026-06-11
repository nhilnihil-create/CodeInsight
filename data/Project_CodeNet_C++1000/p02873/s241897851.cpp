#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> l(n + 1), r(n + 1);
	int now = 0;
	rep(i, n) {
		if (s[i] == '<')
			now++;
		else
			now = 0;
		l[i + 1] = now;
	}
	now = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '>')
			now++;
		else
			now = 0;
		r[i] = now;
	}
	ll ans = 0;
	rep(i, n + 1) ans += max(l[i], r[i]);
	cout << ans << endl;
	return 0;
}