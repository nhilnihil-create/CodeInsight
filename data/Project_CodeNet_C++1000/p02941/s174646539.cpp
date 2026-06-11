#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

constexpr int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
constexpr int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template <class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vi a(n), b(n);
	REP(i, n)cin >> a[i];
	REP(i, n)cin >> b[i];
	queue<int> q;
	REP(i, n) {
		if (b[i] > b[(i + 1) % n] + b[(i + n - 1) % n]) {
			q.push(i);
		}
	}
	auto calc = [&](int p) {
		int c = (b[p] - a[p]) / (b[(p + 1) % n] + b[(p + n - 1) % n]);
		return c;
	};
	ll ans = 0;
	while (!q.empty()) {
		int p = q.front(); q.pop();
		int res = calc(p);
		b[p] -= res * (b[(p + 1) % n] + b[(p + n - 1) % n]);
		ans += res;
		if (calc((p + 1) % n) > 0)q.push((p + 1) % n);
		if (calc((p + n - 1) % n) > 0)q.push((p + n - 1) % n);

	}
	bool ok = true;
	REP(i, n)if (a[i] != b[i])ok = false;
	if (ok)cout << ans << endl;
	else cout << -1 << endl;
}