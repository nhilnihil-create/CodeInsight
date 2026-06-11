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
#define rep3(i, m, n) for(ll i=m;i<=(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1e18

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }

void solve_abc_d() {
	ll n, m;
	ll a, b;
	ll x, y, z;
	//ll h, w;
	ll k;
	//string s, rs;
	ll l_ans = 0;

	cin >> n >> k;
	ll r, s, p;
	cin >> r >> s >> p;
	string t;
	cin >> t;

	V dp(n + 5, 0);
	map<char, ll> point;
	point['r'] = p;
	point['s'] = r;
	point['p'] = s;
	vector<ll> cnt(n + 5, 0);
	rep(i, n) {
		if (i >= k) {
			if (t[i] == t[i - k]) {
				if (cnt[i - k] % 2 == 0) {
					chmax(dp[i + 1], dp[i]);
				}
				else{
					chmax(dp[i + 1], dp[i] + point[t[i]]);
				}
				cnt[i] = cnt[i - k] + 1;
			}
			else {
				chmax(dp[i + 1], dp[i] + point[t[i]]);
			}
		}
		else {
			chmax(dp[i + 1], dp[i] + point[t[i]]);
		}
	}

	cout << dp[n] << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_d();

	return 0;
}
