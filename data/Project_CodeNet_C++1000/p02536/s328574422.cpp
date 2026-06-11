#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	a = a % MOD;
	while (b > 0) {
		if (b & 1) {res = (res * a) % MOD; b--;}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

vl p(100005);
vl siz(100005);

ll get(ll u) {
	return p[u] = (p[u] == u ? u : get(p[u]));
}

void unions(ll u, ll v) {
	u = get(u);
	v = get(v);
	if (u == v)
		return;
	if (siz[u] > siz[v])
		swap(u, v);
	p[u] = v;
	siz[v] += siz[u];
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		p[i] = i;
		siz[i] = 1;
	}
	for (ll i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		unions(u, v);
	}
	set <ll> s;
	for (ll i = 1; i <= n; i++) {
		ll z = get(p[i]);
		s.insert(z);
	}
	cout << (ll)s.size() - 1 << "\n";

}
