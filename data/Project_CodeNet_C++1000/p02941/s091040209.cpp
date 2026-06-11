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
#include <string>
#include <unordered_map>
#include <vector>

#define MOD 1000000007
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
		cout << fixed << setprecision(11);
	}
};
initializer _____;

int N, M, K, T, Q;
signed main() {
	cin >> N;
	vector< ll > A(N);
	vector< ll > B(N);
	rep(i, N) cin >> A[i];
	rep(i, N) cin >> B[i];
	priority_queue< pair< ll, ll > > q;
	rep(i, N) q.push(make_pair(B[i], i));
	ll ans = 0;
	while (!q.empty()) {
		pair< ll, ll > p = q.top();
		q.pop();
		int i = p.second;
		int i1 = ((p.second - 1) % N + N) % N;
		int i2 = (p.second + 1) % N;
		if (B[i] == A[i])
			continue;
		if (B[i] < A[i]) {
			ans = -1;
			break;
		}
		int tmp = (B[i] - A[i]) / (B[i1] + B[i2]);
		//cout << i << " " << B[i1] << endl;
		if (tmp == 0) {
			ans = -1;
			break;
		}
		ans += tmp;
		B[i] -= tmp * (B[i1] + B[i2]);
		if (B[i] != A[i]) {
			q.push(make_pair(B[i], i));
		}
	}
	bool f = true;
	rep(i, N) if (A[i] != B[i]) f = false;
	cout << (f ? ans : -1) << endl;
	return 0;
}