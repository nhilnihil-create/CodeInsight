#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ins insert
#define eb emplace_back
#define endl '\n'
#define ll long long
#define ld long double
#define vl vector<ll>
#define tc ll t; cin >> t; while (t--)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define sz(c) (ll) c.size()
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define trav(x,c) for(auto &x : c)
#define _for(i,a,n) for(ll i = a ; i < n ; ++i)
#define _rfor(i,a,n) for(ll i = n-1 ; i >= a ; --i)
#define dx(x) cout << #x << ": " << x << endl;
#define dc(c) trav(x,c) cout << x << " "; cout << endl;
#define dm(m) trav(x,m) cout << x.f << " " << x.s << endl;
#define godspeed ios::sync_with_stdio(0); cin.tie(0);
#define INF 10000007LL

ll pwr(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1) res = res*a;
		a = a*a;
		b >>= 1;
	}
	return res;
}

int main() {
    godspeed;
    ll n; cin >> n;
    vl v(n+1); _for(i,1,n+1) cin >> v[i];
    sort(all(v));

    ll ans = INF;
    _for(i,1,101) {
    	ll mx = 0;
    	_for(j,1,n+1) mx += pwr(abs(v[j] - i),2);
    	ans = min(mx,ans);
    }

    cout << ans;


}	