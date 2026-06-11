#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define P(x) cout << (x) << "\n"
#define p(x) cout << (x)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vv(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i));
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a), i##_len=(n); i>i##_len; --i)
#define len(x) ((int)(x).size())
#define mp make_pair
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
const constexpr int MAX = 1e5;
const constexpr ll INF = 1LL<<32;
vi G[MAX], indeg(MAX, 0), out;
vb V(MAX, false);
int n;
inline void bfs(int s) {
	deque<int> dq;
	dq.eb(s);
	V[s] = true;
	int u, v;
	while(!dq.empty()) {
		u = dq.front(); dq.pop_front();
		out.eb(u);
		rep(i, 0, len(G[u])) {
			v = G[u][i];
			if(--indeg[v] == 0 && !V[v]) {
				V[v] = true;
				dq.eb(v);
			}
		}
	}
}
inline void tsort() {
	rep(u, 0, n) rep(i, 0, len(G[u])) ++indeg[G[u][i]];
	rep(u, 0, n) if(indeg[u] == 0 && !V[u]) bfs(u);
	rep(i, 0, len(out)) P(out[i]);
}
int main() {
	int m; cin >> n >> m;
	int s, t;
	rep(i, 0, m) {
		cin >> s >> t;
		G[s].eb(t);
	}
	tsort();
	return 0;
}