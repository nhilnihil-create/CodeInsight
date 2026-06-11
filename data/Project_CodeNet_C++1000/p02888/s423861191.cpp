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
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_d() {
	ll n, m;
	ll a, b;
	//ll x, y;
	ll h, w;
	ll k;
	ll l_ans = 0;

	cin >> n;

	V len(n);
	rep(i, n) cin >> len[i];

	sort(ALL(len));

	ll idx1, idx2;
	ll cnt;
	rep(a, n) {
		rep2(b, a + 1, n) {
			auto itr1 = upper_bound(ALL(len), len[b] - len[a]);
			idx1 = itr1 - len.begin();
			auto itr2 = lower_bound(ALL(len), len[a] + len[b]);
			idx2 = itr2 - len.begin();

			cnt = max(0LL, (ll)(idx2 - b - 1));
			l_ans += cnt;
		}
	}

	cout << l_ans << "\n";

	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_d();

	return 0;
}
