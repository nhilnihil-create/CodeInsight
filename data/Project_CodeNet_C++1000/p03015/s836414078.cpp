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
ll mod                = 1e9 + 7;
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
long long modpow(long long a, long long n, long long mod=(1LL<<62)){
	long long res = 1;
	while (n > 0){
		if (n & 1)
		res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}
void COMinit() {// テーブルを作る前処理
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long COM(int n, int k){ // 二項係数:nCk計算
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
	string l;
	COMinit();
	ll ans = 0LL;
	cin >> l;
	int one = 0;
	reverse(all(l));
	for (int i = l.size() - 1; i >= 0;i--){
		if(l[i]=='1'){
			ans += modpow(3,i , mod)*modpow(2,one,mod)%mod;
			one++;

		}
		ans %= mod;
	//	clog << ans << endl;
		
	}
	ans += modpow(2, one, mod);
	cout << ans%mod << endl;
}
/*
0:0 0
1:0 1
  1 0
10:00 10
   10 00
11:11 00
   00 11
   10 01
   01 10
100:000 100
    100 000
101 (2^2)
110 (2^2)
111 (2^3)
1 :0   ==1
1 1 : 1== 1+2=3
1 2 1 : 11 == 1+2*2+4=9
1 3 3 1:111 =1+3*2+3*4+8=27
1 4 6 4 1: 1111 = 1+4*2+6*4+4*8+16=81
nCk : 1..xn.1 で1がkこ立っている == 3^n
1がnこ立っているかいくつかが分かれば一発
*/