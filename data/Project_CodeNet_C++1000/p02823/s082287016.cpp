#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define ld long double
#define ff first
#define ss second
const ll mod =   1e9 +7  ;
ll multiply(ll a, ll b ){ return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b) {     return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) { return ((a%mod) - (b % mod)+ mod) % mod ; }
////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
void solve(){
    ll n , a , b ;
    cin >> n >> a >> b ;
    if((b-a)%2==0){
        cout << (b-a)/2 ;
    }
    else{
        ll nb = b-(a-1);
        ll ans = a-1 + (nb-1)/2 + (1-nb%2) ;
        ll na = a+(n-b) ;

        ll d = n-na ;
        ans = min(ans,n-b+d/2+d%2);
        cout << ans ;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1 ;
   // cin >> t ;
    while(t--){
        solve( );
    }
}
