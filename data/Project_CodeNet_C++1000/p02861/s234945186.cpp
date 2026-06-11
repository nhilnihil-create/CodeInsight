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
const ll mod = 1e6 + 3;


vii c;

int main(){
    fastio;
    ll n,x,y;
    string s;
    cin >> n ;
    f(i,0,n){
        cin >> x >> y;
        c.push_back({x,y});
    }
    sort(all(c));
    ld ans = 0;
    while( 1 ){
        f(i,1,n){
            ans += (sqrt( 1.0*(c[i].ff -c[i-1].ff)*(c[i].ff -c[i-1].ff) + 1.0*(c[i].ss -c[i-1].ss)*(c[i].ss -c[i-1].ss)  ));
        }
        if(next_permutation(all(c)) == false) break;
        
    }
    f(i,2,n+1) ans /= 1.0*i;
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}