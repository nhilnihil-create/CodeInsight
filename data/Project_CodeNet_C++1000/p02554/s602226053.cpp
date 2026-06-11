/* https://codeforces.com/contest/1360/problem/H */
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vs = vector<string>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;
using ld = double;

#define f first
#define s second 
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define pb push_back
#define	lb lower_bound
#define	ub upper_bound
#define	sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define ins insert

const int MAX = INT_MAX;
const ll MOD = 1e9+7;

int main() {
	int N;
	cin>>N;
	ll a1 = 1;
	for (int i = 0;i < N;++i) {
		a1 *= 10;
		a1 %= MOD;
	}

	ll a2 = 1;
	for (int i = 0;i < N;++i) {
		a2 *= 9;
		a2 %= MOD;
	}

	a2 *= 2;
	a2 %= MOD;

	ll a3 = 1;
	for (int i = 0;i < N;++i) {
		a3 *= 8;
		a3 %= MOD;
	}

	a1 = a1 - a2;
	if (a1 < 0) {
		a1 = MOD - (abs(a1));
	}

	cout<<(a1+a3)%MOD<<endl;
	return 0;
}
