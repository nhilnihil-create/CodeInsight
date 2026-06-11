#include<bits/stdc++.h>
using namespace std;
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define endl '\n'
#define ld long double
#define FOR(i,a,n) for (int i=(a);i<=(n);++i)
#define RFOR(i,a,n) for (int i=(n);i>=(a);--i)
#define FI(i,n) for (int i=0; i<(n); ++i)
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

const ll MAXN = 2e5 + 10;
ll l[MAXN],r[MAXN];
const ll MOD = 1e9 + 7;
ll fact[MAXN];

void solve(){
    fact[0] = 1;

    FOR(i,1,MAXN-1) fact[i] = (fact[i-1]*i)%MOD;

    ll n; cin>>n;
    string s; cin>>s;

    if(s.front() == 'W' || s.back() == 'W'){
        cout<<0<<endl;
        return;
    }

    l[0] = 1,r[0] = 0;
    ll prev = 1;
    FOR(i,1,2*n-1){
        l[i] = l[i-1],r[i] = r[i-1];
        if(s[i] == s[i-1]){
            if(prev == 1) r[i]++,prev = 0;
            else l[i]++,prev = 1;
        }else {
            if(prev == 1) l[i]++,prev = 1;
            else r[i]++,prev = 0;
        }
    }

    if(l[2*n-1] != r[2*n-1]){
        cout<<0<<endl;      
        return;
    }

    ll ans = 1;

    FOR(i,0,2*n-1){
        if(r[i] > r[i-1]){
            ll left = l[i] - r[i-1];
            ans = (ans * left)%MOD;
        } 
    }

    ans = (ans * fact[n])%MOD;
    cout<<ans<<endl;
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