#include <bits/stdc++.h>

#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define af(i,a,b) for( ll i = a; i >= b ; i--)
#define rep(i,a,b,k) for(ll i = a; i < b ; i+= k )
#define arep(i,a,b,k) for( ll i = a; i >= b ; i-= k)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (ll) a.size()
#define all(a) a.begin(), a.end()
#define sor(a) sort( a.begin(), a.end() )
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ller ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
const ll MAX = 1e6 + 3;
const ll inf = 1e18;
const ll mod = 1e9 + 7;


vii c;

ll bp(ll a,ll e){
    if(e == 0) return 1;
    if(e&1) return (a*bp(a,e-1))%mod;
    ll x = bp(a,e>>1);
    return (x*x)%mod;
}

ll inv(ll a){
    return bp(a,mod-2);
}

ll mul(ll a,ll b){
    return (a*b)%mod;
}
int main(){
    fastio;
    ll n,x,y;
    string s;
    cin >> x >> y;
    ll a = x -(x+y)/3, b = y - (x+y) /3;
    if( (x+y)%3 != 0 || a<0 || b<0) cout << "0\n";
    else{
        ll ans = 1;
        f(i,1,a+1) ans = mul(ans,mul(a+b+1-i,inv(i)));
        cout << ans << endl;
    }
    
    return 0;
}
