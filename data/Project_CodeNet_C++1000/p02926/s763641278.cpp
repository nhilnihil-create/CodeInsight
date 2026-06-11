#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;
const double EPS = 1e-9;

#define ndl cout << '\n'
#define sz(v) int(v.size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define present(a, x) (a.find(x) != a.end())
#ifdef LOCAL
#define db(...) ({cout << "> Line " << __LINE__  \
		<< ": "; _db(#__VA_ARGS__, __VA_ARGS__);})
#else
#define db(...) true
#endif
template<class T>
void _db(const char *dbStr, T e) {
	cout << dbStr << " = " << e << endl;
}
template<class T, class... L>
void _db(const char *dbStr, T e, L... r) {
  while(*dbStr != ',') cout << *dbStr++;
  cout << " = " << e << ','; _db(dbStr + 1, r...);
}
template<class S, class T>
ostream& operator<<(ostream& o, const map<S, T>& v) {
	o << "["; int i = 0;
	for (const pair<S, T>& pr : v) o << (!i++ ? "" : ", ") << "{"
	<< pr.fs << " : " << pr.sc << "}"; return o << "]";
}
template<template <class, class...> class S, class T, class... L>
ostream& operator<<(ostream& o, const S<T, L...>& v) {
	o << "["; int i = 0;
	for (const auto& e : v) o << (!i++ ? "" : ", ") << e;
	return o << "]";
}
template<class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& pr) {
	return o << "(" << pr.fs << ", " << pr.sc << ")";
}
ostream& operator<<(ostream& o, const string& s) {
	for (const char& c : s) o << c; return o;
}
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
template<class T> using VVV = VV<V<T>>;
using ll = long long;
using pii = pair<int, int>;
using vi = V<int>;
using vii = V<pii>;
using vvi = VV<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using si = set<int>;
using usi = unordered_set<int>;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

double DEG_to_RAD(double d) {
	return d * PI / 180.0;
}
double RAD_to_DEG(double r) {
	return r * 180.0 / PI;
}

template<class T>
struct Point {
	T x, y;
	Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
	bool operator<(Point<int> oth) const {
		return mp(x, y) < mp(oth.x, oth.y);
	}
	bool operator<(Point<double> oth) const {
		if (fabs(x - oth.x) > EPS)
			return x < oth.x;
		return y < oth.y;
	}
	bool operator>(Point<T> oth) const {
		return oth < *this;
	}
	bool operator<=(Point<int> oth) const {
		return mp(x, y) <= mp(oth.x, oth.y);
	}
	bool operator>=(Point<int> oth) const {
		return oth <= *this;
	}
	bool operator==(Point<int> oth) const {
		return mp(x, y) == mp(oth.x, oth.y);
	}
	bool operator==(Point<double> oth) const {
		return fabs(x - oth.x) < EPS
				&& fabs(y - oth.y) < EPS;
	}
	bool operator!=(Point<T> oth) const {
		return !(*this == oth);
	}
	// + and - convert to type of LHS
	template<class S>
	Point<T> operator+(Point<S> oth) const {
		return Point<T>(x + oth.x, y + oth.y);
	}
	template<class S>
	Point<T> operator-(Point<S> oth) const {
		return Point<T>(x - oth.x, y - oth.y);
	}
	Point<double> scale(double sc) {
		return Point<double>(x * sc, y * sc);
	}
	// rotate p by theta degrees CCW w.r.t origin (0, 0)
	Point<double> rotate(double theta) {
		double rad = DEG_to_RAD(theta);
		return Point<double>(x * cos(rad) - y * sin(rad),
				x * sin(rad) + y * cos(rad));
	}
};

template<class T>
double dist(Point<T> p1, Point<T> p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

template<class T>
double angleSigned(Point<T> a, Point<T> o, Point<T> b) {
	a = a - o, b = b - o;
	double rot = -atan2(a.y, a.x);
	b.rotate(RAD_to_DEG(rot));
	double ret = atan2(b.y, b.x);
	if (ret < 0)
		ret += 2 * PI;
	return ret;
}

template<class T>
vector<Point<T>> radialSweep(vector<Point<T>> P) {
	vector<Point<T>> ret = P;
	Point<T> pivot = Point<int>(0, 0), pivotR = Point<T>(pivot.x + 1, pivot.y);
	// ret[0] = P[idx]
	sort(ret.begin(), ret.end(), [pivot, pivotR](Point<T>& p1, Point<T>& p2) {
		if (p1 == p2)
			return false;
		if (p1 == Point<int>(0, 0))
			return true;
		if (p2 == Point<int>(0, 0))
			return false;
		double ang1 = angleSigned(pivotR, pivot, p1);
		double ang2 = angleSigned(pivotR, pivot, p2);
		// since we're dealing with values in range [0, 2 * PI],
		// we use very small EPS
		if (fabs(ang1 - ang2) < 1e-18)
			return dist(pivot, p1) < dist(pivot, p2);
		return ang1 < ang2;
	});
	return ret;
}

int N;
V<Point<int>> pts;

int main() {
	#ifdef LOCAL
	auto stTime = clock();
	#endif
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cout.precision(25);
	cin.tie(0);

	cin >> N;
	pts.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> pts[i].x >> pts[i].y;
	pts = radialSweep(pts);
	for (int i = 0; i < N; ++i)
		pts.pb(pts[i]);
	double ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < i + N; ++j) {
			Point<int> curr(0, 0);
			for (int k = i; k <= j; ++k) {
				curr = curr + pts[k];
			}
			ans = max(ans, dist(curr, Point<int>(0, 0)));
		}
	}
	cout << fixed << ans << '\n';

	#ifdef LOCAL
	cout << "\n\n\nExecution time: " <<
		(clock() - stTime) * 1e3 / CLOCKS_PER_SEC << " ms" << endl;
	#endif
    return 0;
}
