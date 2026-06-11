#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

// [---]
//  [-]
//   [--]
// 123321
//
//
// 101101
// [[[]]]
//
//
// [-]
//  [-]
//     []
//
// 100111
// [[]][]

const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n; cin >> n;
	string a; cin >> a;
	
	ll res = 1, open = 0, close = 0;
	for (char c: a) {
		ll depth = open-close;
		if (depth%2 == (c == 'W')) {
			open++;
		} else {
			close++;
			res = res * depth % MOD;
		}
		if (open < close) res = 0;
	}
	if (open != close) res = 0;
	FOR(i,1,n+1) res = res*i % MOD;
	cout << res << endl;
}

