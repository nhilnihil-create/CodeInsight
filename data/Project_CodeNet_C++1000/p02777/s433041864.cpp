#include <bits/stdc++.h>
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define sz(x) x.size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rep(i, x, n) for (ll i = x; i < n; i++)
#define fastio() ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0)
#define endl '\n'

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;

template <class T> inline T RD(T &a) {T x; cin >> x; return a = x;}
template <class T> inline T gcd(T a, T b) {if (b) return gcd(b, a % b); else return a;}
template <class T> inline T lcm(T a, T b) {return (a * b) / gcd(a,b);}

signed main()
{
//	freopen("THREEPRIMES.inp", "r", stdin); freopen("THREEPRIMES.out", "w", stdout);
	fastio();

	string s, t; cin >> s >> t;
	int a, b; cin >> a >> b;
	string p; cin >> p;
	if (p == s) cout << a - 1 << ' ' << b;
	else cout << a << ' ' << b - 1;
}
