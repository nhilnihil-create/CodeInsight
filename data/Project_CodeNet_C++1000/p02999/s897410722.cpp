#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define gcd __gcd
#define lcm(a, b) ((a) * (b) / gcd((a), b))
#define all(x) x.begin(), x.end()
#define rep(i, x, n) for (ll i = x; i < n; i++)
#define fastio() ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0)
#define endl '\n'

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

template <class T> inline T RD(T &a) {T x; cin >> x; return a = x;}

signed main()
{
//	freopen("TEXT.inp", "r", stdin); freopen("TEXT.out", "w", stdout);
	fastio();

	int x, a; cin >> x >> a;
	if (x >= a) cout << 10;
	else cout << 0;


}
