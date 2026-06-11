#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using VE = vector<T>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
bool asikiri(int n, VL& a) {
	bool res = false;
	if (n == 0 && a[0] != 1) res = true;
	else if (n != 0 && a[0] != 0) res = true;
	return res;
}
int main() {
	int n;
	cin >> n;
	VL a(n + 1);
	rep(i, n + 1) {
		cin >> a[i];
	}
	VL sum(n + 1, 0);
	sum[n] = a[n];
	for (int i = n - 1; i >= 0; i--) {
		sum[i] += sum[i + 1] + a[i]; // これが深さiの最大値
	}
	ll ans = 1;
	ll now = 1;
	if (asikiri(n, a)) {
		puts("-1");
		return 0;
	}
	/*
	深さiの最大値は
	min(2^i,a(dからnまでの総和)
	2^iは二分木は頂点を二つしか増やせないから,
	a(dからnまでの総和)は葉の数を変えることなく次の頂点の数を減らすことができないから
	*/
	rep1(i, n) {
		now *= 2;
		chmin(now, sum[i]);
		ans += now;
		now -= a[i];
		if (now < 0) {
			puts("-1");
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}