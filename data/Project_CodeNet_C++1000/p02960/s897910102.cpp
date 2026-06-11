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

ll dp[100005][13];

void solve_abc_d() {
	string s;
	cin >> s;
	ll n = s.size();

	ll ans;

	reverse(ALL(s));

	rep(i, 100005)rep(j, 13) {
		dp[i][j] = 0;
	}

	rep(d, 10) {
		if (s[0] == '?' || d == s[0] - '0') {
			dp[1][d] = 1;
		}
	}

	ll x = 10;
	rep2(i, 1, n) {
		rep(d, 10) {
			if (s[i] == '?' || d == s[i] - '0') {
				rep(j, 13) {
					dp[i + 1][(j + d * x) % 13] += dp[i][j];
					dp[i + 1][(j + d * x) % 13] %= MOD;
				}
			}
		}
		x = (x * 10) % 13;
	}

	ans = dp[n][5];

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
