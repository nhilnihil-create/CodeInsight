#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T,V> &x){cerr<<'{';__print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
template<typename T>
void __print(const T &x){int f=0;cerr<<'{';for(auto &i:x)cerr<<(f++ ? "," : ""),__print(i);cerr<<"}";}
void _print(){cerr<<"]\n";}
template<typename T,typename... V>
void _print(T t, V... v) {__print(t);if(sizeof...(v))cerr<<", ";_print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define sz(x) (int)x.size()                         					
#define all(x) x.begin(), x.end()           		
#define lb lower_bound                  	
#define ub upper_bound             		
                                   	
typedef long long ll;           		
typedef pair<int, int> pii;     	
typedef pair<ll, ll> pll;       	
typedef long double ld;
          						
template<typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;    
template<typename T> void print(T x){cerr<<x<<'\n';}
inline ll bip(ll x,ll n,ll mod){ll res=1;while(n){if(n&1){res=(res*x)%mod;}x=(x*x)%mod;n>>=1;}return res;}                 		
																															 
const int maxn = 1e9;
const ll inf = 1e18;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const int N = 5e5 + 10;

string s;
int r[N], a[N];

void solve() {
	cin >> s;

	int n = sz(s);

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '>') r[i] = r[i + 1] + 1;
		else r[i] = 0;
	}

	if (s[0] == '>') a[0] = r[0];
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			if (s[i - 1] == '<') a[i] = a[i - 1] + 1;
		} else {
		    if (s[i - 1] == '<') a[i] = max(a[i - 1] + 1, r[i]);
		    else a[i] = r[i];
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++) ans += a[i];
	cout << ans;
}
 
int main() {
    SpeedForce;
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
        cout << '\n';
    }
}    