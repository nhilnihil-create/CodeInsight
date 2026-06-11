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
#define LLINF 1000000000000000000

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }

void solve_abc_d() {
	ll n, k;
	ll l_ans = -LLINF;

	cin >> n >> k;
	V p(n), c(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	rep(i, n) cin >> c[i];

	rep(i, n) {
		ll cnt = 0;
		ll tot = 0;
		ll now = i;
		while (true) {
			cnt++;
			tot += c[now];
			now = p[now];
			if (now == i) {
				break;
			}
		}

		ll cnt2 = 0;
		ll tot2 = 0;
		now = i;
		while (true) {
			cnt2++;
			tot2 += c[now];

			if (cnt2 > k) break;

			ll num = (k - cnt2) / cnt;
			chmax(l_ans, tot2 + max(0LL, tot * num));

			now = p[now];
			if (now == i) {
				break;
			}
		}
	}

	cout << l_ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_d();

	return 0;
}
