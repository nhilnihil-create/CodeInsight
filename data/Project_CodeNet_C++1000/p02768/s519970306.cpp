#include <bits/stdc++.h>
using namespace std;
#define x_ real()
#define y_ imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
pair<int, int> dirs[] = { {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };
const ll mod = 1e9 + 7;
const ll N = 2e5 + 7;
ll fact[N];
ll inv[N];


ll add(ll a, ll b) {
	return ((a%mod) + (b%mod))%mod;
}


ll mult(ll a, ll b) {
	return ((a%mod) * (b%mod))%mod;
}


ll sub(ll a, ll b) {
	return ((a%mod) - (b%mod) + mod)%mod;
}

ll fp(ll b, ll e) {
	if (!e)
		return 1;
	ll ans = fp(b, e/2);
	ans = mult(ans, ans);
	if (e&1)
		ans = mult(ans, b);
	return ans;
}


void pre() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mult(i, fact[i-1]);
		inv[i] = fp(fact[i], mod-2);
	}
}

ll ncr(ll n, ll r) {
	ll ans = 1;
	for (ll i = n; i >= n-r+1; i--) {
		ans = mult(ans, i);
	}
	return mult(ans, inv[r]);
}


int main() {
	fastIO;
	pre();
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = sub(fp(2, n), add(add(ncr(n, a), ncr(n, b)), 1));
	cout << ans;

}

