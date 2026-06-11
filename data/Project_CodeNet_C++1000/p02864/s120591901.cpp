#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
const int INF_INT = 1 << 25;
const long long MOD = 1e9 + 7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
const int loose = 0;
const int tight = 1;

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

//グラフ関連
struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}


void solve() {
	ll n, kk;
	cin >> n >> kk;
	Array h(n);
	REP(i, n) cin >> h[i];

	vec<vvec<ll>> dp(n + 1, vvec<ll>(kk + 1, vec<ll>(n+1, INF)));//何番目か、変更回数、最後に操作
	dp[0][0][0] = 0;
	REP(i, n) {
		REP(j, kk + 1) {
			REP(k, i+1) {
				ll num = (k == 0) ? h[i] : max(h[i] - h[k-1], 0LL);//操作回数
				chmin(dp[i + 1][j][i + 1], dp[i][j][k] + num);//操作
				if (j+1<=kk) chmin(dp[i + 1][j + 1][k], dp[i][j][k]);//変更
			}
		}
	}
	
	ll ans = INF;
	REP(i, kk + 1) REP(j, n + 1) chmin(ans, dp[n][i][j]);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}