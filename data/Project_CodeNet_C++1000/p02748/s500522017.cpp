#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, start_index, num)  (a).begin()+(start_index),(a).begin()+(num)

int main() {
	int a, b, m;
	cin >> a >> b >> m;
	vector<int>as(a);
	vector<int>bs(b);
	FOR(i, 0, a-1) {
		cin >> as[i];
	}
	FOR(i, 0, b - 1) {
		cin >> bs[i];
	}
	int res = INF;
	FOR(i, 1, m) {
		int x, y, c;
		cin >> x >> y >> c;
		res = min(res, as[x - 1] + bs[y - 1] - c);
	}
	sort(ALL(as));
	sort(ALL(bs));
	res = min(res, as[0] + bs[0]);
	pv(res)
	return 0;
}