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
#define dm(m) trav(x,m) cout << x.f << "->" << x.s << endl;
#define godspeed cin.tie(0) -> sync_with_stdio(0);

const int INFI = 2e9 + 5;
const ll INFLL = 1e18 + 5;
const ll N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ld PIE = acos(-1.0);

int main() {
    godspeed;

 	ll n, m, x; cin >> n >> m;
 	while(m--) {
 		cin >> x;
 		n -= x;
 	}

 	if(n >= 0) cout << n;
 	else cout << -1;
}