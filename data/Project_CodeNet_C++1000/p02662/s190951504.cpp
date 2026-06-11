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
	os << "}" << endl;
	
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
ll mod                = 998244353LL;
int n;
long long modpow(long long a, long long n, long long mod = (1LL << 62)) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	int s;
	ll ans = 0LL;
	cin >> n >> s;
	Vi a(n);
	cin >> a;
	// vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));  // can
	// reach?
	VV res(n + 1, V(s + 1, 0LL));
	//	dp[0][0] = true;
	res[0][0] = 1;
	sort(all(a));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			//		dp[i + 1][j] = true;
			res[i + 1][j] += res[i][j] * 2LL;
			res[i + 1][j] %= mod;

			if (j >= a[i]) {
				//	dp[i + 1][j] = true;
				res[i + 1][j] += res[i][j - a[i]];
				res[i + 1][j] % mod;
			}
		}
	}

	// clog << dp << endl;
		//clog << res << endl;
	cout << res[n][s]%mod << endl;
}
/*
3000*3000
深さ優先探索
jが変われば使われたことを指す
*/