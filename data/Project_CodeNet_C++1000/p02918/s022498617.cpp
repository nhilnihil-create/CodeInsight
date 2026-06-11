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

void solve_abc_d() {
    ll n, k;
	cin >> n >> k;

	string s;
	cin >> s;
	
	V lr;
	ll cnt = 0;
	ll first = 0;
	char now = s[0];
	rep(i, n) {
		if (now == s[i]) {
			cnt++;
		}
		else {
			lr.push_back(cnt);
			first += cnt - 1;
			cnt = 1;
			now = s[i];
		}
	}
	lr.push_back(cnt);
	first += cnt - 1;

	ll ans = min(first + 2 * k, n - 1);

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
