//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define loopinc(i, a, b, inc) for(int i = a; i < (b); i += inc)
#define loop(i, a, b) for(int i = a; i < (b); i++)
#define rep(i, n) loop(i, 0, n)
#define rrep(i, n) for (int i = n-1; i >= 0; i--)
#define endl "\n"
#define all(c) (c).begin(),(c).end()
#define lloopinc(i, a, b, inc) for(ll i = a; i < (b); i += inc)
#define lloop(i, a, b) for(ll i = a; i < (b); i++)
#define lrep(i, n) lloop(i, 0, n)
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef tuple<int, int, int> tiii;
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
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

constexpr ll mod = 1000000007;
ll nc2(ll n) { return n*(n-1)/2; }
signed main() {
	// freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	ll acc = 0;
	loop(i, k, n+2) {
		acc += nc2(n+1)-nc2(n+1-i)-nc2(i)+1;
		acc %= mod;
	}
	cout << acc % mod << endl;
}
