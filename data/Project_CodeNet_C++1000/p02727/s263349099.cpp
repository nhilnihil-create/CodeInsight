#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define repi(i, x) \
	for (auto i = (x).begin(), i##_fin = (x).end(); i != i##_fin; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
string solve(bool a) { return ((a) ? "Yes" : "No"); }
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int, int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long, long long> P;
typedef vector<P> VP;
template <class T>
inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{";
	rep(i, v.size()) {
		if (i) os << ",";
		os << v[i];
	}
	os << "}";
	return os;
}
template <class T, class U>
istream& operator>>(istream& is, pair<T, U>& p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
	rep(i, v.size()) { is >> v[i]; }
	return is;
}
const long long INFLL = 1LL << 60;
const int INF         = 1 << 30;
const double PI       = acos(-1);
int main() {
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	priority_queue<ll, vector<ll>, greater<ll>> p, q;
	V r(c);
	ll cnt;
	ll ans = 0LL;
	rep(i, a) {
		cin >> cnt;
		p.push(cnt);
	};
	rep(i, b) {
		cin >> cnt;
		q.push(cnt);
	}
	cin >> r;
	sort(all(r));
	while (p.size() > x) {
		p.pop();
	}
	while (q.size() > y) {
		q.pop();
	}
	clog << "A" << endl;
	rep(i, c) {
		if (q.top() > p.top()) {
			p.push(r[i]);
			p.pop();
		} else {
			q.push(r[i]);
			q.pop();
		}
	}
	clog << "A" << endl;
	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}
	while (!p.empty()) {
		ans += p.top();
		p.pop();
	}
	cout << ans << endl;
}