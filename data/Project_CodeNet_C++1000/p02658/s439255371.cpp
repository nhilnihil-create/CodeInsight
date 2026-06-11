#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//value at the index->find_by_order(index), index->order_of_key(elme) [both in O(logn)]
//mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
//cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define setbits(x)      __builtin_popcountll(x)
#define leadzero(x)     __builtin_clz(x)
#define trailzero(x)    __builtin_ctz(x)
#define bitsparity(x)   __builtin_parity(x)
#define mod             1000000007
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll              long long 
#define pre(y,x)        fixed<<setprecision(y)<<x
#define dbg1(x)         cerr << "|" << #x << ": " << (x) << "|\n";
#define dbg2(x,y)       cerr << "|" << #x << ": " << (x) << "|" << #y << ": " << (y) << "|\n";
#define dbg3(x,y,z)     cerr << "|" << #x << ": " << (x) << "|" << #y << ": " << (y) << "|" << #z << ": " << (z) << "|\n";
#define ff              first
#define ss              second
#define pb              push_back
#define eb              emplace_back
#define popb            pop_back
#define endl            '\n'
#define all(v)          v.begin(), v.end()
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<pii> vii;
typedef vector<pll> vll; 
typedef vector<ll> vl; 
typedef vector<vl> vvl;
typedef vector<string> vs;
ll power(ll a,ll b){if(b==0) return 1;ll res=1;while(b>0){if(b&1) res *= a;a *= a;b >>=1;}return res;}
int is(int n){if(n==1) return 0;for(int i=2;i*i<=n;i++){if(n%i==0) return false;}return true;}
bool ispoweroftwo(ll x){ return (x&&!(x&(x-1)));}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int inf = 1e9;
const double pi = acos(-1);
const ll INF = 1e18;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline void solve(){
		ll n;
		cin >> n ;
		ll a[n], ans=1;
		for(int i=0; i<n; ++i) {
			cin >> a[i];
			if(a[i] == 0) {
				cout << "0" ;
				return;
			}
		}
		for(int i=0; i<n; ++i) {
			if(a[i]<=1000000000000000000/ans) {
				ans *= a[i];
			} else {
				cout << "-1" ;
				return;
			}
		}
		cout << ans << endl;
		
}	
int main(){
		FIO;
//		int t; cin >> t;
//		while(t--)
		solve();
		return 0;	
}
/*

*/