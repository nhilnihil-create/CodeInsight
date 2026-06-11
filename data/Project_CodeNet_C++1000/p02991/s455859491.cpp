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
const int N = 101010;
using Pi = P<int>;
VV e(N);
VV dp(N, V(3, upper));
void dijkstra(int s) {
	priority_queue<Pi, VE<Pi>, greater<Pi>>  pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int d = pq.top().first, p = pq.top().second;
		pq.pop();
		if (dp[p][d % 3] < d) continue;
		rep(i, e[p].size()) {
			int np = e[p][i];
			if (chmin(dp[np][(d + 1) % 3], dp[p][d % 3] + 1)) {
				pq.push(make_pair(d + 1, np));
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		e[x].push_back(y);
	}
	int s, t;
	cin >> s >> t;
	s--, t--;
	dp[s][0] = 0;
	dijkstra(s);
	if (dp[t][0] == upper) cout << -1 << endl;
	else cout << dp[t][0] / 3 << endl;
	return 0;
}