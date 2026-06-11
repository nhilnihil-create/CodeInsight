#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
using pll = pair < ll, ll >;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std :: endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif

#define pb push_back
#define mp make_pair
#define fastIo() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1e9 + 7, INF = INT_MAX, N = 1e5 + 10;

vector<ll>a, b, c, d;
ll n, m, q; 
ll ans = 0;

void solve(vector<ll>&v) {
	if(v.size() == n) {
		ll sum = 0;
		for(ll i = 0 ; i < q; i++) {
			if((v[b[i]] - v[a[i]]) == c[i]) {
				sum += d[i];
			}
		}
		ans = max(sum, ans);
	} else {
		ll st = 1;
		if(v.size()) st = v.back();
		for(ll i = st; i <= m; i++) {
			v.push_back(i);
			solve(v);
			v.pop_back();
		}
	}
}

int main(){
	cin >> n >> m >> q;
	a.resize(q);
	b.resize(q);
	c.resize(q);
	d.resize(q);
	for(ll i = 0; i < q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		a[i]--;
		b[i]--;
	}
	vector<ll>v;
	solve(v);
	cout << ans << endl;
}