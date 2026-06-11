#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rep3(i, m, n) for(ll i=m;i<=(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1e18

// 素因数分解
map<ll, ll> prime_factor(ll n) {
	map<ll, ll> ret;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void solve_abc_d() {
	ll n, m;
	ll a, b;
	ll x, y, z;
	//ll h, w;
	ll k;
	string s, rs;
	ll l_ans = 0;

	cin >> a >> b;

	x = gcd(a, b);

	map<ll, ll> mv;

	mv = prime_factor(x);

	l_ans = mv.size() + 1;
	
	cout << l_ans << "\n";

	return;
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed;
	cout << setprecision(15);

	solve_abc_d();

	return 0;
}
