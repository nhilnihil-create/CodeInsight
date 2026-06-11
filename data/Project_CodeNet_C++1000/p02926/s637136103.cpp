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

int pow2(int n) { return 1 << n; }
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
struct point {
	double x, y;
	point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	point operator+(const point &rhs) const {
		return point(x + rhs.x, y + rhs.y);
	}
	point operator-(const point &rhs) const {
		return point(x - rhs.x, y - rhs.y);
	}
	point operator*(const double d) const {
		return point(x * d, y * d);
	}
};
double dot(const point &a, const point &b) {
	return a.x * b.x + a.y * b.y;
}
double det(const point &a, const point &b) {
	return a.x * b.y - a.y * b.x;
}
double arg(const point &a) {
	return atan2(a.y, a.x);
}
double abs(const point &a) {
	return sqrt(a.x * a.x + a.y * a.y);
}
struct circle {
	double r, x, y;
	circle(double r = 0.0, double x = 0.0, double y = 0.0) : r(r), x(x), y(y) {}
	circle(double r, point p) : r(r), x(p.x), y(p.y) {}
	point getCenter() { return point(x, y); }
};
double dist(point a, point b) {
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x * x + y * y);
}
bool getCircle(point p1, point p2, double r, point &pc1, point &pc2) {
	bool stat = true;
	point p3;
	double d, l, dx, dy;
	p3.x = (p1.x + p2.x) * 0.5;
	p3.y = (p1.y + p2.y) * 0.5;
	r *= r;
	l = (p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y);
	if (r >= l) {
		d = sqrt(r / l - 1.0);
		dx = d * (p2.y - p3.y);
		dy = d * (p2.x - p3.x);

		pc1.x = p3.x + dx;
		pc1.y = p3.y - dy;

		pc2.x = p3.x - dx;
		pc2.y = p3.y + dy;
	} else {
		stat = false;
	}

	return stat;
}
bool comp(const point &a, const point &b) {
	return arg(a) < arg(b);
}
int N, M, K, T, Q, H, W;
signed main() {
	cin >> N;
	vector< point > P(N);
	rep(i, N) cin >> P[i].x >> P[i].y;
	sort(P.begin(), P.end(), comp);
	vector< point > S(N + 1, point(0, 0));
	rep(i, N) S[i + 1] = S[i] + P[i];
	double ans = 0.0;
	rep(i, N) rep(j, N) {
		if (i < j) {
			point p = S[j] - S[i];
			chmax(ans, abs(p));
		} else {
			point p = S[N] + S[j] - S[i];
			chmax(ans, abs(p));
		}
		//cout << i << " " << j << " " << ans << endl;
	}
	//rep(i, N) cout << P[i].x << " " << P[i].y << endl;
	cout << ans << endl;
	return 0;
}