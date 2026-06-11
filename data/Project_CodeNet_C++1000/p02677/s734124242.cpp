#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
 
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
const ll SIZE = 2e5 + 5;
const ll MOD  = 1e9 + 7;

#define PI 3.14159265

ll a, b, h, m;
double res, angle, mi, ho;

int main() { speedhack()

	cin >> a >> b >> h >> m;

	mi = m * 6;
	ho = h * 30 + (double(m) / 60) * 30;

	angle = abs (mi - ho);

	if (angle > 180)
		angle = 360 - angle;
	
	res = sqrt(a * a + b * b - 2 * a * b * cos (angle * M_PI / 180.0));
	cout << fixed << setprecision(20) << res;
	


	return 0;
}
