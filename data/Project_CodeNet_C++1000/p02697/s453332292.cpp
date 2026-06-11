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
	int n, m;
	cin >> n >> m;
	VPi ans(m);
	int inter = ((m+1) / 2);
	int at    = 0;
	if(n%2==0){
	for (int i = 0; i < inter; i++) {
		ans[i].F = i+1;
		if(i==inter-1){
			ans[inter - 1].S = ans[inter - 1].F + 1;
		}
	}

	for (int i = inter - 2; i >=0 ;i--){
		ans[i].S = ans[i + 1].S+1;
	}
	clog << ans[inter - 1] << endl;
	// inter*2+1
	for (int i = inter; i < m; i++) {
		ans[i].F = (inter + 1 + i);
		if(i==m-1){
			ans.back().S = ans.back().F + 2;
		}
		}
		
	for (int i = m - 2; i >= inter;i--){
		ans[i].S = ans[i + 1].S+ 1;
	}
	//	if(ans[inter].S-ans[inter].F==ans[inter].F-ans[inter].S+n){
	//		ans[inter] = mp(ans.back().F + 1, ans.back().S - 1);
	//	}
	}else{
	//	ans[0] = mp(n/2, n/2+2);
		for (int i = 0; i < m;i++){
			ans[i].F = i+1;
		}
		ans.back().S = ans.back().F + 1;
		for (int i = m - 2; i >= 0;i--){
			ans[i].S = ans[i + 1].S + 1;
		} }
	rep(i, m) { cout << ans[i].F << " " << ans[i].S << endl; }
}
/*
1 2 |3 5| 4 7

1 2 3 4  ... 5 6 7 8  | 9 10 11 12 13... (14) 15 16 17 18 19 ... 9 (9)
07 05 03 01 10 08 06 04 02 || 9 10
12 14 16 18 09 11 13 15 17

1 12  13
11 2
6 2
1 2 |5 6 => 2 5  3 4


1 2

4 5

1

1 7
2 6
3 5
1
3
2
1 2 3 4 5 7

1
2
2
*/