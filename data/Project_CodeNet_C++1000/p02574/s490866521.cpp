#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
const int p = 1000005;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	vector<int> a(p);
	a[1] = 1;
	repl(i, 2, p) {
		if (a[i]) continue;
		for (int j = i; j < p; j += i) {
			if (a[j] == 0) a[j] = i;
		}
	}
	int n;
	cin >> n;
	vector<int> vec(n);
	rep(i, n) cin >> vec[i];
	set<int> s;
	bool flag = 0;
	rep(i, n) {
		set<int> t;
		int k = vec[i];
		while (true) {
			if (k == 1) break;
			t.insert(a[k]);
			if (k == a[k]) break;
			k /= a[k];
		}
		for (auto nt : t) {
			if (s.count(nt)) {
				flag = 1;
				i = n;
				break;
			}
			s.insert(nt);
		}
	}
	if (flag == 0) {
		cout << "pairwise coprime\n";
		return 0;
	}
	int g = vec[0];
	rep(i, n) g = gcd(g, vec[i]);
	if (g == 1)
		cout << "setwise coprime\n";
	else
		cout << "not coprime\n";
	return 0;
}