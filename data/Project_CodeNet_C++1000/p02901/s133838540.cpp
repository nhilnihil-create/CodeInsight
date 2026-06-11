#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using VVV = vector<vector<vector<int>>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VVVL = vector<vector<vector<ll>>>;
template<class T> using pq = priority_queue<T>;
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
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -MOD * MOD;
const long double pi = 3.141592653589793;
int main() {
	int n, m;
	cin >> n >> m;
	vector<P<int>> part(m);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		int syugo = 0;
		rep(j, b) {
			int k;
			cin >> k;
			k--;
			syugo |= (1 << k);
		}
		part[i] = make_pair(syugo, a);
	}
	VV dp(m + 1, V((1 << n), upper));
	dp[0][0] = 0;
	rep(i, m) {
		rep(j, (1 << n)) {
			chmin(dp[i + 1][j], dp[i][j]);
			int nj = (j | part[i].first);
			chmin(dp[i + 1][nj], dp[i][j] + part[i].second);
		}
	}
	if (dp[m][(1 << n) - 1] == upper) cout << -1 << endl;
	else cout << dp[m][(1 << n) - 1] << endl;
	return 0;
}