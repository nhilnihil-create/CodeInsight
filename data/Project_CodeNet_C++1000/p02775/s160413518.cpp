/*Author - Shubham Gupta (@shubham107)*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;		typedef vector<int> vi;
typedef vector<vl> vvl;	  	typedef vector<vi> vvi;
typedef pair<ll, ll> pll;	typedef pair<int, int> pii;
#define forn(i,n) for(int i=0;i<n;i++)
#define rforn(i,n) for(int i=n-1;i>=0;i--)
#define forne(i,n) for(int i=1;i<=n;i++)
#define forse(i,s,e) for(int i=s;i<e;i++)
#define rforse(i,s,e) for(int i=e-1;i>=s;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define MOD 1000000007
#define F first
#define S second
#define pb push_back
#define fill(a,x) memset(a,x,sizeof a);
#define trav(a,x) for(auto &a:x)
#define INF	ll(1e18)
#ifdef SHUBHAM107
#include "../code-pieces/trace.h"
#else
#define trace(args...)
#endif

ll modpow(ll a, ll b, ll m = MOD) {
	a %= m; ll res = 1; while (b) {if (b & 1)res = res * a % m; a = a * a % m; b >>= 1;}
	return res;
}
ll bpow(ll a, ll b) {ll res = 1; while (b) {if (b & 1)res = res * a; a = a * a; b >>= 1;} return res;}
ll modinv(ll a) {return modpow(a, MOD - 2, MOD);}
void graph(vvi &adj, int m) {int x, y; forn(i, m) {cin >> x >> y; adj[x - 1].pb(y - 1); adj[y - 1].pb(x - 1);}}

const int mxN = 2e5 + 5;
void solve() {
	string s;
	cin >> s;
	int n = sz(s);
	vvi dp(n+1, vi(2));
	dp[0][1] = 1; 
	forn(i, n){
		dp[i+1][0] = min(dp[i][0] + s[i]-'0', dp[i][1] + 10 - (s[i] - '0'));
		dp[i+1][1] = min(dp[i][0] + s[i]-'0' + 1, dp[i][1] + 10 - (s[i] - '0' + 1));
	}
	cout << dp[n][0];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef SHUBHAM107
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
}
