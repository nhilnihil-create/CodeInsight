#include <bits/stdc++.h>
using namespace std;

#define fa(x,v) for(auto x:v)
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define spc " "
#define endl '\n'
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define len(s) (ll)int(s.length())
#define sz(v) (ll)int(v.size())
#define MOD 1000000007

void Fast_IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    freopen("debug.out","w",stderr);
    #endif
} 

// Code Here

int main()
{
    // Fast_IO();
    ll n; cin >> n;
    vector < pair<ll,ll> > edge;
    f(_,1,n-1) {
    	ll u, v; cin >> u >> v;
    	if(u > v) swap(u,v);
    	edge.pb(mp(u,v));
    }
    ll sv = 0, se = 0;
    f(i,1,n) sv += i * (n-i+1);
    fa(x,edge) se += x.ff * (n-x.ss+1);
    cout << sv - se << endl;
    return 0;
}