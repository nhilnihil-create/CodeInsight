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
#define no {cout << -1; return 0;}
#define sz(c) (ll) c.size()
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define trav(x,c) for(auto &x : c)
#define _for(i,a,n) for(ll i = a ; i < n ; ++i)
#define _rfor(i,a,n) for(ll i = n-1 ; i >= a ; --i)
#define dx(x) cout << #x << ": " << x << endl;
#define dc(c) trav(x,c) cout << x << " "; cout << endl;
#define godspeed ios::sync_with_stdio(0); cin.tie(0);

int main() {
    godspeed;
    ll n, m; cin >> n >> m;
    ll ans = 0;
    map<ll,ll> mp;

    ll x, y;
    while(m--) {
    	cin >> x >> y;

    	if(mp.count(x) && mp[x] != y) no;
    	if(n != 1 && x == 1 && y == 0) no;

    	mp[x] = y;
    }

    if(!mp.count(1) && n > 1) mp[1] = 1;
    else if(!mp.count(1)) mp[1] = 0;

    _for(i,1,n+1) cout << mp[i];

}