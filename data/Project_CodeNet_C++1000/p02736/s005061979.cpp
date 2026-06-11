#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define v vector
#define ALL(x) x.begin(),x.end()
#define rALL(x) x.rbegin(),x.rend()
#define endl '\n'
#define DEBUG

template<typename T> void DBG(const char* name, T&& H) {
	cerr << name << " = " << H << ')' << endl;
}

template<typename T, typename... Args> void DBG(const char* names, T&& H, Args&&... args) {
	const char* NEXT = strchr(names+1, ',');
	cerr.write(names, NEXT-names) << " = " << H << " |";
	DBG(NEXT+1, args...);
}

#ifdef DEBUG
	#define dbg(...) cerr << __FUNCTION__ << ' ' <<__LINE__ << " : (", DBG(#__VA_ARGS__, __VA_ARGS__)
#else
	#define dbg(...)
#endif

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ld PI = acos(-1.0);
const ll maxN = 1e6+1;

void Solve() {
	vector<ll> fact(maxN, 0);
	for(ll i = 2; i <= maxN; i *= 2) {
		for(ll j = i; j <= maxN; j += i) {
			fact[j] ++;
		}
	}
	for(ll i = 1; i <= maxN; i ++) {
		fact[i] += fact[i-1];
	}
	ll n;
	cin >> n;
	vector<ll> a(n+1);
	set<ll> dif;
	for(ll i = 1; i <= n; i ++) {
		char ch;
		cin >> ch;
		a[i] = ch-'1';
		dif.insert(a[i]);
	}
	if(dif.size() == 1) {
		cout << 0 << endl;
		return;
	}
	if(dif.size() == 3) {
		for(ll i = 1; i <= n; i ++) {
			if(a[i] == 2) a[i] = 0;
		}
	}
	if(dif.size() == 2) {
		if((*dif.begin()) == 1) {
			for(ll i = 1; i <= n; i ++) {
				if(a[i] == 2) a[i] = 0;
			}
		}
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i ++) {
		ll parity = fact[n-1]-fact[i-1]-fact[n-i];
		if(parity == 0) ans ^= a[i];
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int tt = 1;
	while(tt --) {
		Solve();
	}
	
	return 0;
}