#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
#define int long long
#define double long double
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VP;
typedef vector<string> VS;
typedef priority_queue<int> PQ;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define fore(i,a) for(auto &i:a)
#define REP(i,n) for(int i=0;i<n;i++)
#define eREP(i,n) for(int i=0;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define eFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define rSORT(c) sort((c).rbegin(),(c).rend())
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))
#define INF 1000000000
#define LLINF 9223372036854775807
#define mod 1000000007
#define eps 1e-12 
//priority_queue<int,vector<int>, greater<int> > q2;

struct UnionFind {
	VI par, s;
	UnionFind(int N) :par(N), s(N) {
		REP(i, N)par[i] = i;
		REP(i, N)s[i] = 1;
	}
	int root(int x) {
		if (par[x] == x)return x;
		return par[x] = root(par[x]);
	}
	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx == ry)return;
		if (!(same(x, y)))s[ry] += s[rx];
		par[rx] = ry;
	}
	bool same(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
	int size(int x) {
		return s[root(x)];
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	UnionFind uni(N);
	while (Q--) {
		int t, u, v; cin >> t >> u >> v;
		if (t)cout << uni.same(u, v) << endl;
		else uni.unite(u, v);
	}

	return 0;
}

