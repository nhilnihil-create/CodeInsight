#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1 ; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1 ; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9+100;
const bool debug = 0;
/***************************************/

int dist(int h, int w) {
	return h * h + w * w;
}

int main() {
	int H, W;
	while (cin >> H >> W, H || W) {
	int mi = INF;
	pii ans(INF, 0);
	int d = dist(H, W);

	FOR(h, 1, 151) {
		FOR(w, h + 1, 151) {
			int curd = dist(h, w);
			if (curd > d || (curd == d && h > H)) {
				if (chmin(mi, curd)) ans = pii(h, w);
				else if (mi == curd) chmin(ans, pii(h, w));
			}
		}
	}
	if (debug) putchar('@');
	cout << ans.fi << " " << ans.se << endl;
	}
return 0;
}
