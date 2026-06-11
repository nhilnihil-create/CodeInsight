#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int main() {
	int H, W, M;
	cin >> H >> W >> M;
	
	vector<vector<int>> yv(H);
	vector<int> xcnt(W); // [i] := x = i の対象の個数
	
	vector<int> h(M), w(M);
	REP(i, M) {
		scanf("%d %d", &h[i], &w[i]);
		--h[i]; --w[i];
		yv[h[i]].emplace_back(i);
		++xcnt[w[i]];
	}
	
	int ans = 0;
	
	multiset<int> ms; // x 座標ごとの対象の個数の max を求めたい
	REP(i, W) ms.insert(xcnt[i]);
	REP(i, H) {
		for (int idx : yv[i]) {
			ms.erase(ms.find(xcnt[w[idx]]));
			ms.insert(xcnt[w[idx]] - 1);
		}
		
		chmax(ans, yv[i].size() + *(--ms.end()));
		
		for (int idx : yv[i]) {
			ms.erase(ms.find(xcnt[w[idx]] - 1));
			ms.insert(xcnt[w[idx]]);
		}
	}
	
	cout << ans << endl;
	return 0;
}
