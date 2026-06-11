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
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
void add(ll& a, ll b) {
	a += b;
	if (a >= MOD) while (a >= MOD) a -= MOD;
}
int main() { // 意外と取れる行動が少ない
	int n, s;
	cin >> n >> s;
	V a(n);
	rep(i, n) {
		cin >> a[i];
	}
	/*
	1.そもそもTからピックしない→dp[i+1][j]+=dp[i][j]
	2.Tからピックするが、それを部分集合に加えない→dp[i+1][j]+=dp[i][j]
	3.Tからピックして、それを部分集合に加える→dp[i+1][j+a[i]]+=dp[i][j]
	*/
	VVL dp(n + 1, VL(s + 1, 0)); // i番目までで、1,2,3の行動を行ったときに総和がjとなるようなものの数
	dp[0][0] = 1;
	rep(i, n) {
		rep(j, s + 1) {
			add(dp[i + 1][j], 2 * dp[i][j]);
			if (j + a[i] <= s) {
				add(dp[i + 1][j + a[i]], dp[i][j]);
			}
		}
	}
	cout << dp[n][s] << endl;
	return 0;
}