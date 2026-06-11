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
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
int m;
void bfs(int x, VV& tree, vector<bool>& visited, ll& ans, VL& mul) {
	queue<int> que;
	que.push(x);
	visited[x] = true;
	while (!que.empty()) {
		int X = que.front();
		que.pop();
		visited[X] = true;
		ans *= mul[X];
		ans %= MOD;
		mul[X] = (X == 0) ? m : m - 1;
		for (auto c : tree[X]) {
			if (!visited[c]) {
				que.push(c);
				mul[X]--;
				mul[c] = mul[X];
				visited[c] = true;
			}
		}
	}
}
int main() { // 問題文はしっかり読め!!!
	int n;
	cin >> n >> m;
	VV G(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].push_back(b); G[b].push_back(a);
	}
	ll ans = 1;
	VL mul(n, m);
	vector<bool> visited(n, false);
	bfs(0, G, visited, ans, mul);
	cout << ans << endl;
	return 0;
}