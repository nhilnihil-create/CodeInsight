#include<bits/stdc++.h>
using namespace std; 
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll              long long 
#define pre(y,x)        fixed<<setprecision(y)<<x
#define dbg(x)          cerr << "[" << #x << ": " << (x) << "]\n";
#define ff              first
#define ss              second
#define pb              push_back
#define popb            pop_back
#define dbg1(x)         cerr << "|" << #x << ": " << (x) << "|\n";
#define dbg2(x,y)       cerr << "|" << #x << ": " << (x) << "|" << #y << ": " << (y) << "|\n";
#define dbg3(x,y,z)     cerr << "|" << #x << ": " << (x) << "|" << #y << ": " << (y) << "|" << #z << ": " << (z) << "|\n";
#define all(v)          v.begin(), v.end()
#define reset(a, b)     memset(a, b, sizeof(a))
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii; 
typedef vector<ll> vl; 
typedef vector<vl> vvl;
ll power(ll a,ll b){if(b==0) return 1;ll res;while(b>0){if(b&1) res *= a;a *= a;b >>=1;}return res;}
int is(int n){if(n==1) return 0;for(int i=2;i*i<=n;i++){if(n%i==0) return false;}return true;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int inf = 1000000000;
const ll INF = 1000000000000000000;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll solve(int s){
	ll dp[s+1]={};
	dp[0] = 1;
	for(ll i=3; i<=s; ++i){
		for(ll j=3; j<=i; ++j){
//			dbg3(i, j, dp[i-j]);
			(dp[i] += dp[i-j]) %= mod;
		}
	}
	return dp[s];
}
int main(){
	int s;
	cin >> s;
	cout << solve(s) ;
	return 0;
}