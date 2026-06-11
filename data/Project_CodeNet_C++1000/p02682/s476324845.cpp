#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef unsigned long long ull;
typedef long long ll;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define speedhack() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define form(i, n) for (size_t i = 0; i < size_t(n); ++i)
#define forn(i, n) for (size_t i = 1; i <= size_t(n); ++i)

template<class T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod(ll a, ll b) { return (a%b+b)%b; }
ll gcd(ll x, ll y) { return __gcd(x, y); }
ll lcm(ll x, ll y) { return x * 1ll * y / gcd(x, y); }
 
const ll MAXN = 1e18;
const ll SIZE = 6e6 + 6;
const ll MOD  = 1e9 + 7;

ll a, b, c, k, res;

int main() { speedhack()

	cin >> a >> b >> c >> k;

	ll step = min (a, k);
	k -= step;
	res += step;

	step = min (b, k);
	k -= step;

	step = min (c, k);
	res -= step;
	cout << res;

	return 0;
}
