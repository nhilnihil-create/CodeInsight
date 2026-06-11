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
	int n;
	ll ans = 0;
	cin >> n;
	VPi data(n);
	cin >> data;
	V sum, diff;
	rep(i, n) {
		sum.pb(data[i].F + data[i].S);
		diff.pb(data[i].F - data[i].S);
	}
	sort(all(sum));
	sort(all(diff));
	cout << max(sum.back() - sum.front(), diff.back() - diff.front()) << endl;
}
/*
|X_i-x_j|+|y_i-y_j|
=max(x_i-x_j,x_j-x_i)+max(y_i-y_j,y_j-y_i)
=max(x_i+y_i-x_j-y_j,x_j+y_j-x_i-y_i,x_i+y_j-x_j-y_i,x_j+y_i-x_i-y_j)
x_i+y_i=A_i
x_i-y_i=B_i
=max(A_i-A_j,B_j-A_i,B_i-B_j,B_j-B_i)
find:max(|X_i-x_j|+|y_i-y_j|)
=max(max(x_i-x_j,x_j-x_i)+max(y_i-y_j,y_j-y_i))
=max(max(A_i-A_j,B_j-A_i,B_i-B_j,B_j-B_i))
=max(max(|A_i-A_j|,|B_i-B_j|))
=max(max(A_i)-min(A_j),max(B_i)-min(B_j))

*/