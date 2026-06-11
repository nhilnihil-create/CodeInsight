#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
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

template <typename T>
struct SegTree {
	T init_val;
	int n;
	vector<T> dat;
	
	SegTree() = default;
	SegTree(int _n, T init_val) : init_val(init_val) {
		n = 1;
		while (n < _n) n *= 2;
		dat.resize(n * 2 - 1, init_val);
	}
	
	void update(int i, T x) {
		i += n - 1;
		dat[i] = min(dat[i], x);
		while (i > 0) {
			i = (i - 1) / 2;
			dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
		}
	}
	
	void set(int i, T x) {
		dat[i + n - 1] = x;
		update(i, x);
	}
	
	// 探索範囲[a,b), 現在見ているkノード[l,r)
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		
		if (r <= a || b <= l) return init_val;
		if (a <= l && r <= b) return dat[k];
		return min( query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r) );
	}
};

int N, K;
int H[300], h[300];
ll dp[301][301][301];
ll smn[301][301];

int main() {
	cin >> N >> K;
	REP(i, N) scanf("%d", H + i);
	
	vector<int> cx(N);
	REP(i, N) cx[i] = H[i];
	cx.push_back(0);
	sort(ALL(cx));
	cx.erase(unique(ALL(cx)), cx.end());
	
	REP(i, N) h[i] = lower_bound(ALL(cx), H[i]) - cx.begin();
	
	fill(dp[0][0], dp[N + 1][0], longINF);
	
	dp[0][0][0] = 0;
	FOR(i, 1, N + 1) {
		REP(j, K + 1) {
			REP(k, N + 1) smn[j][k] = dp[i - 1][j][k];
			for (int k = N - 1; k >= 0; k--) chmin(smn[j][k], smn[j][k + 1]);
		}
		REP(j, K + 1) {
			ll mn = longINF;
			REP(k, N + 1) chmin(mn, dp[i - 1][j][k] + max(cx[h[i - 1]] - cx[k], 0));
			if (j < K) chmin(dp[i][j + 1][h[i - 1]], mn);
			
			REP(k, N + 1) {
				if (j) chmin(dp[i][j][k], smn[j - 1][k]);
				if (k) chmin(dp[i][j][k], dp[i][j][k - 1] + cx[k] - cx[k - 1]);
			}
			chmin(dp[i][j][h[i - 1]], mn);
		}
	}
	
	ll ans = longINF;
	REP(j, K + 1) REP(k, N + 1) chmin(ans, dp[N][j][k]);
	cout << ans << endl;
	
	return 0;
}
