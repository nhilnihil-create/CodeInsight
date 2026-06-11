
// Problem : D - Bouquet
// Contest : AtCoder - AtCoder Beginner Contest 156
// URL : https://atcoder.jp/contests/abc156/tasks/abc156_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ld pii=3.14159265359;
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 1000000001; //check the limits, dummy
ll mod_pow(ll x,ll n) {
	if (n == 0) return 1;
	ll res = mod_pow(x*x % MOD, n / 2);
	if (n & 1) res = res * x % MOD;
	return res;
}

ll comb(ll n, ll x) {
	ll ret = 1,k=1;
	F0R(i,x)ret = (ret * (n - i))%MOD;
	F0R(i,x)k = (k * (x-i))%MOD;
	k = mod_pow(k, MOD - 2);
	ret = (ret*k + MOD) % MOD;
	return ret;
}
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0);    
	int N,A,B;
	cin>>N>>A>>B;
	ll ans=mod_pow(2,N)-1;
	ans=ans-comb(N,A);
	if(ans<0)ans+=MOD;
	ans=ans-comb(N,B);
	if(ans<0)ans+=MOD;
	cout<<ans<<endl;
	return 0;
}
// read the question correctly (ll vs int)
// template by bqi343
 

