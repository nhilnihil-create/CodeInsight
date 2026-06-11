#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

ll y[2005][2005];
ll t[2005][2005];

void solve_abc_d() {
	ll h, w;
	cin >> h >> w;

	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}

	rep(i, h)rep(j, w) {
		if (s[i][j] == '#') {
			y[i][j] = 0;
			t[i][j] = 0;
		}
		else {
			if (j != 0) {
				y[i][j] = y[i][j - 1] + 1;
			}
			else {
				y[i][j] = 1;
			}

			if (i != 0) {
				t[i][j] = t[i - 1][j] + 1;
			}
			else {
				t[i][j] = 1;
			}
		}
	}

	rrep(i, h - 1, 0)rrep(j, w - 1, 0) {
		if (j != w - 1) {
			if (y[i][j] != 0 && y[i][j + 1] != 0) {
				y[i][j] = y[i][j + 1];
			}
		}

		if (i != h - 1) {
			if (t[i][j] != 0 && t[i + 1][j] != 0) {
				t[i][j] = t[i + 1][j];
			}
		}
	}

	ll ans = 0;
	rep(i, h)rep(j, w) {
		ans = max(ans, y[i][j] + t[i][j] - 1);
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed;
	//cout << setprecision(7);

	solve_abc_d();

	return 0;
}
