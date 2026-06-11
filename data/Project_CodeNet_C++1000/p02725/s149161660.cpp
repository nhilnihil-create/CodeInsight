#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define deb(x)     cout << #x << " = "<<x<<endl

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)

int MOD = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;


ll gcd(ll  a , ll b) {
	return (b == 0) ? a : gcd(b, a % b);
}
ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
ll powmod(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
ll modinv(ll n, ll p)
{
	return powmod(n, MOD - 2, MOD);
}
void max_self(ll &a, ll b) {
	a = max(a, b);
}
bool is_ap(vl v, int n) {
	ll d = v[1] - v[0];
	F0R(i, n) {
		if (v[i] != v[0] + i * d)
			return false;
	}
	return true;
}


int main(int argc, char const *argv[])
{
	// two magical lines to speed up IO
	cin.tie(0);
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int  k , n;
	cin >> k >> n;
	// vi al, ar;
	// int ln, rn;
	// int hlf = k / 2;
	// F0R(i, n) {
	// 	int x;
	// 	cin >> x;
	// 	if (x <= hlf) {
	// 		ar.pb(x);
	// 	}
	// 	else if (x > hlf) {
	// 		al.pb(k - x);

	// 	}


	// }
	// sort(all(al));
	// sort(all(ar));
	// ln = al.size();
	// rn = ar.size();
	// int ans;
	// if (ln > 0 && rn > 0) {
	// 	ans = min(k - al[0] - ar[0], al[ln - 1] + ar[rn - 1]);
	// }
	// else if (ln == 0) {
	// 	ans = ar[rn - 1] - ar[0];
	// }
	// else if (rn == 0) {
	// 	ans = al[rn - 1] - al[0];
	// }

	// cout << ans << endl;
	int a[n];
	int mx = 0;
	F0R(i, n) {
		cin >> a[i];

	}
	sort(a, a + n);
	F0R(i, n) {
		if (i > 0) {
			mx = max(a[i] - a[i - 1], mx);
		}
		mx = max(k - a[n - 1] + a[0], mx);
	}
	cout << (k - mx) << endl;



}


