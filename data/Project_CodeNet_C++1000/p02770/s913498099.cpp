#include <bits/stdc++.h>
////////////////////////////////////////////////////////////
#define all(x) (x).begin(), (x).end() 
const int inf = 1e9;
const long long INF=1e15;
#define endl '\n'
#define forn(i, n) for(int i=0;i<(n);++i)
#define pb push_back
#define eb emplace_back
#define fastio ios::sync_with_stdio(false);cin.tie(0); //cout.tie(0);

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

int main() {
	ll k, q; cin >> k >> q;
	vll d(k); forn(i, k) cin >> d[i];
	while(q--) {
		ll n, x, m; cin >> n >> x >> m;
		ll ans = n-1;
		n--; // 0~n-1
		// (aj mod m) = (aj+1 mod m)
		ll p1 = 0; // period1
		for(ll i=0;i<k;i++) if(d[i]%m == 0) p1++;
		ans -= p1 * (n/k);
		for(ll i=0;i<n%k;i++) if(d[i]%m == 0) ans--;
		
		// (aj mod m) > (aj+1 mod m)
		// quotient : an-1/m - a0/m
		ll q=0, r=x%m; // quotient, remainder
		ll pq=0, pr=0; // preiod q, period r
		for(ll i=0;i<k;i++) {
			pr += d[i]%m;
			pq += pr/m; pr = pr%m;
		}
		
		q += pq*(n/k); r += pr*(n/k);
		q += r/m; r = r%m;
		
		for(ll i=0;i<n%k;i++) {
			r += d[i]%m;
			q += r/m; r = r%m;
		}
		
		ans -= q;
		cout << ans << endl;
	}
}