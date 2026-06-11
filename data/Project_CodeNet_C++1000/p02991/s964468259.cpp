#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 1000000007
#define MOD2 998244353
#define int long long
#define EPS 1e-9
//#define PI 3.14159265358979

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

template < typename T >
ostream &operator<<(ostream &os, const vector< T > &A) {
	for (int i = 0; i < A.size(); i++)
		os << A[i] << " ";
	os << endl;
	return os;
}
template <>
ostream &operator<<(ostream &os, const vector< vector< int > > &A) {
	int N = A.size();
	int M;
	if (N > 0)
		M = A[0].size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			os << A[i][j] << " ";
		os << endl;
	}
	return os;
}

typedef pair< int, int > pii;
typedef long long ll;

struct edge {
	int from, to, d, c;
	edge(int _from = 0, int _to = 0, int _d = 0, int _c = 0) {
		from = _from;
		to = _to;
		d = _d;
		c = _c;
	}
	bool operator<(const edge &rhs) const {
		return (d == rhs.d) ? (c < rhs.c) : (d < rhs.d);
	}
};
struct aabb {
	int x1, y1, x2, y2;
	aabb(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

typedef vector< edge > edges;
typedef vector< edges > graph;
struct flow {
	int to, cap, rev, cost;
	flow(int to = 0, int cap = 0, int rev = 0, int cost = 0) : to(to), cap(cap), rev(rev), cost(cost) {}
};
typedef vector< vector< flow > > flows;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {-1, 0, 1, 0};
const int ci[5] = {0, 0, -1, 0, 1};
const int cj[5] = {0, -1, 0, 1, 0};
const ll LINF = LLONG_MAX / 2;
const int INF = INT_MAX / 2;
const double PI = acos(-1);

int pow2(int n) { return 1LL << n; }
template < typename T, typename U >
bool chmin(T &x, const U &y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}
template < typename T, typename U >
bool chmax(T &x, const U &y) {
	if (x < y) {
		x = y;
		return true;
	}
	return false;
}

struct initializer {
	initializer() {
		cout << fixed << setprecision(20);
	}
};
initializer _____;
vector< int > dijkstra(graph &G, int s) {
	///stat must have "<"&">"
	///init d=vector<stat>
	vector< int > d(G.size(), LINF);
	d[s] = 0;
	//init q=p-queue<pair<stat,index> >
	priority_queue< pii, vector< pii >, greater< pii > > q;
	q.push(pii(0, s));

	while (!q.empty()) {
		pii p = q.top();
		q.pop();
		if (d[p.second] < p.first)
			continue;
		for (int i = 0; i < G[p.second].size(); i++) {
			edge e = G[p.second][i];
			if (p.first + e.d < d[e.to]) {
				d[e.to] = p.first + e.d;
				q.push(pii(d[e.to], e.to));
			}
		}
	}
	return d;
}
int N, M, K, T, Q, H, W;
signed main() {
	cin >> N >> M;
	vector< vector< edge > > G(3 * N);
	rep(i, M) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		G[u].emplace_back(u, v + N, 1);
		G[u + N].emplace_back(u, v + 2 * N, 1);
		G[u + 2 * N].emplace_back(u, v, 1);
	}
	int s, t;
	cin >> s >> t;
	--s;
	--t;
	vector< int > d = dijkstra(G, s);
	if (d[t] == LINF) {
		cout << -1 << endl;
	} else {
		cout << d[t] / 3 << endl;
	}

	return 0;
}