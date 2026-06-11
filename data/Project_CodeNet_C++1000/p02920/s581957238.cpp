#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define endl '\n'
#define ld long double
#define FOR(i,a,n) for (ll i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (ll i=(n);i>=(a);--i)
#define FI(i,n) for (ll i=0; i<(n); ++i)
#define ZERO(a) memset((a),0,sizeof((a)))
#define MINUS(a) memset((a),-1,sizeof((a)))
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(g) g.begin(),g.end()
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
 
/*
░░░░░░░░░░░░░░░░░░░░░░░░░
░░█▀▀▄░░░░░░░░░░░▄▀▀█░░░░
░░█░░░▀▄░▄▄▄▄▄░▄▀░░░█░░░░
░░░▀▄░░░▀░░░░░▀░░░▄▀░░░░░
░░░░░▌░▄▄░░░▄▄░▐▀▀░░░░░░░
░░░░▐░░█▄░░░▄█░░▌▄▄▀▀▀▀█░
░░░░▌▄▄▀▀░▄░▀▀▄▄▐░░░░░░█░
░▄▀▀▐▀▀░▄▄▄▄▄░▀▀▌▄▄▄░░░█░
░█░░░▀▄░█░░░█░▄▀░░░░█▀▀▀░
░░▀▄░░▀░░▀▀▀░░▀░░░▄█▀░░░░
░░░░█░░░░░░░░░░░▄▀▄░▀▄░░░
░░░░█░░░░░░░░░▄▀█░░█░░█░░
░░░░█░░░░░░░░░░░█▄█░░▄▀░░
░░░░█░░░░░░░░░░░████▀░░░░
░░░░▀▄▄▀▀▄▄▀▀▄▄▄█▀░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░
*/
 
// I want to be the very best, like no one ever was, I will battle everyday to claim my rightful place
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_updat
// using namespace __gnu_pbds;
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
// I am questioning life and universe and 
// everything else after looking at this

void solve(){
    ll n; cin>>n;
    ll total_n = (1<<n);

    multiset<ll> m;
    FOR(i,1,total_n){
        ll x; cin>>x; m.insert(-x);
    }

    vector<ll> v;
    v.push_back(*m.begin());
    m.erase(*m.begin());

    FOR(i,1,n){
        ll siz = v.size();
        FOR(j,0,siz-1){
            if(m.upper_bound(v[j]) == m.end()){
                cout<<"No\n";
                return;
            }
            auto val = m.upper_bound(v[j]);
            v.push_back(*val);
            m.erase(val);
        }
    }

    cout<<"Yes\n";
}

signed main(){
 
   FastRead;    
 
    
    ll t;
    t = 1; 
    // cin>>t;
    FOR(i,1,t){
        // cout<<"Case #"<<i<<": ";
        solve();
    }
}