/*
 *  Created on: 2017/06/27
 *      Author: LitMc
 */
#define MYDEBUG
#include <bits/stdc++.h>
#ifdef MYDEBUG
#define dbp(x) cout<<#x<<": "<<x<<endl
#define dbp2(x,y) cout<<#x<<","<<#y<<": "<<x<<","<<y<<endl
#define dbp3(x,y,z) cout<<#x<<","<<#y<<","<<#z<<": "<<x<<","<<y<<","<<z<<endl
#define dbp4(w,x,y,z) cout<<#w<<","<<#x<<","<<#y<<","<<#z<<": "<<w<<","<<x<<","<<y<<","<<z<<endl
#define ifcin(x) std::ifstream cin(x)
#else
#define dbp(x)
#define dbp2(x,y)
#define dbp3(x,y,z)
#define dbp4(w,x,y,z)
#define ifcin(x)
#endif
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rep(i, from, to) for(int i=from; i<to; ++i)
#define REP(i, from, to) for(int i=from; i<=to; ++i)
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::min;
using std::swap;
using std::string;
using std::fill;
using std::pair;
using std::sort;
using std::reverse;
using std::pair;
using std::greater;
using std::priority_queue;
using std::ostream;
using std::unique;

template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i] << endl;
	}
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

struct edge {
	int from, to, cost;
	edge() {
		*this = edge(-1, -1, -1);
	}
	edge(int from_, int to_, int cost_) {
		from = from_;
		to = to_;
		cost = cost_;
	}
	bool operator<(const edge& e) const {
		return cost < e.cost;
	}
	bool operator==(const edge& e) const {
		return (from == e.from && to == e.to && cost == e.cost)
				|| (from == e.to && to == e.from && cost == e.cost);
	}
};
static const double EPS = 1e-14;
typedef std::complex<double> P;
int n, size;
vector<P> p;

void dfs(int rest, P p1, P p2) {
	P s = (p2 - p1) / 3.0 + p1;
	P t = (p2 - p1) * (2.0 / 3.0) + p1;
	P u = (t - s) * P(0.5, sqrt(3) / 2.0) + s;
	if (rest > 1) {
		dfs(rest - 1, p1, s);
		p.push_back(s);
		dfs(rest - 1, s, u);
		p.push_back(u);
		dfs(rest - 1, u, t);
		p.push_back(t);
		dfs(rest - 1, t, p2);
	} else if (rest == 1) {
		p.push_back(s);
		p.push_back(u);
		p.push_back(t);
	}
}

void solve() {
	cin >> n;
	P p1 = P(0, 0), p2 = P(100, 0);
	p.push_back(p1);
	dfs(n, p1, p2);
	p.push_back(p2);
	rep(i,0,(int)p.size())
	{
		printf("%.8f %.8f\n", p[i].real(), p[i].imag());
	}
}

int main() {
	solve();
}