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
	int n, k;
	ll ans = -INF;
	cin >> n >> k;
	vector<vector<tuple<int, ll, ll>>> tri(n, vector<tuple<int, ll, ll>>(33,mt(0,-INF,-INF)));
	int p;
	ll c;
	rep(i, n) {
		cin >> p;
		get<0>(tri[i][0]) = p-1;
	}
	rep(i, n) {
		cin >> c;
		get<1>(tri[i][0]) = c;
		get<2>(tri[i][0]) = c;

	}
	for (int j = 0; j < 32;j++) {
		rep(i, n) { 
			get<0>(tri[i][j+1]) = get<0>(tri[get<0>(tri[i][j])][j]);
			get<1>(tri[i][j+1]) = get<1>(tri[i][j]) +
			                    get<1>(tri[get<0>(tri[i][j])][j]);
			get<2>(tri[i][j+1]) = max(get<2>(tri[i][j]),
			                        get<1>(tri[i][j]) + get<2>(tri[get<0>(tri[i][j])][j]));
		}
	}
//	rep(j,33){
//		rep(i,n){
		//	clog << get<0>(tri[i][j]) << " " << get<1>(tri[i][j]) << " "
		//	     << get<2>(tri[i][j]) << " | ";
//		}
//		clog << endl;
//	}

	clog << endl;
	ll now = 0LL;
	int at;
	rep(i,n){
		at = i;
		now = 0LL;
		for (int j = 32; j >= 0; j--) {
			if (k & (1LL << j)) {
				
				chmax(ans, now + get<2>(tri[at][j]));
				now += get<1>(tri[at][j]);

				at = get<0>(tri[at][j]);
			//	clog << at << " " << now << endl;
			}

		}
	//	clog << " ::"<<now << endl;
	} 
	cout << ans << endl;
}