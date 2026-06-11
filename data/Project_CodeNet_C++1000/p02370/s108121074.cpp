#include "bits/stdc++.h"
#include <sys/timeb.h>
#include <fstream>

using namespace std;

#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define replrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) replrev(i,0,n)
#define repi(itr,ds) for(auto itr=ds.begin();itr!=ds.end();itr++)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define mt make_tuple
#define INF 2000000000
#define INFL 1000000000000000000LL
#define EPS (1e-10)
#define MOD 1000000007
#define PI 3.1415926536
#define RMAX 4294967295

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<P> vP;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<ll> > vvll;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<double> > vvd;
typedef vector<vector<P> > vvP;
typedef priority_queue<int, vector<int>, greater<int> > pqli;
typedef priority_queue<ll, vector<ll>, greater<ll> > pqlll;
typedef priority_queue<P, vector<P>, greater<P> > pqlP;
struct Edge {
	int from, to, cost;
	bool operator<(Edge e) {
		return cost < e.cost;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

class SCCD {
public:
	stack<int> post;
	vb used;

	void dfs(int pos, int par, const Graph &G) {
		used[pos] = true;
		rep(i, G[pos].size()) {
			int to = G[pos][i].to;
			if (used[to])continue;
			dfs(to, pos, G);
		}
		post.push(pos);
	}

	void dfsrev(int pos, int par, const Graph &rev, vi &group) {
		used[pos] = true;
		group.push_back(pos);
		rep(i, rev[pos].size()) {
			int to = rev[pos][i].to;
			if (used[to])continue;
			dfsrev(to, pos, rev, group);
		}
	}

	void SCC(Graph G, vvi &scc, vi &n2g) {
		int N = G.size();
		Graph rev(N);
		rep(i, N) {
			rep(j, G[i].size()) {
				Edge e = G[i][j];
				rev[e.to].push_back(Edge{ e.to,e.from,1 });
			}
		}

		used = vb(N, false);
		rep(i, N) {
			if (!used[i])dfs(i, -1, G);
		}

		fill(all(used), false);
		while (!post.empty()) {
			int pos = post.top();
			post.pop();
			if (used[pos])continue;
			vi group;
			dfsrev(pos, -1, rev, group);
			scc.push_back(group);
		}

		rep(i, scc.size()) {
			rep(j, scc[i].size()) {
				n2g[scc[i][j]] = i;
			}
		}
	}
};

int main() {
	int V, E;
	cin >> V >> E;
	Graph G(V);
	
	rep(i, E) {
		int s, t;
		cin >> s >> t;
		G[s].push_back(Edge{ s,t,1 });
	}

	vvi scc;
	vi n2g(V);

	SCCD sccd;
	sccd.SCC(G, scc, n2g);

	rep(i, V) {
		cout << scc[i][0] << endl;
	}
}