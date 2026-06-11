    #include <bits/stdc++.h>
    #include<math.h>
    #include<algorithm> 
    #define rep(i,n) for (int i = 0; i < (n) ; ++i)
    using namespace std;
    using ll = long long ;
    using P = pair<int, int> ;
    #define PI 3.14159265358979323846264338327950
    #define INF 1e18
    #define mod 1000000007 
     
    int modpow(ll a, ll n, ll p = mod) {
        if(n == 0) return 1 ;
        if(n == 1) return a%p ;
        if(n%2 == 1) return (a*modpow(a, n-1, p))%p ;
        ll t = modpow(a, n/2, p) ;
        return (t%p*t%p) % p ;
    }
    int main (){
        ll n, a, b ;
        cin >> n >> a >> b ;
        ll da = 1 ; 
        ll db = 1 ;
        ll na = a; 
        ll nb = b;
        rep(i, na){
            ll tm = ((n-i) % mod) * (modpow(a, mod-2)) ;
            tm %= mod ;
            da *= tm ;
            da %= mod ;
            a-- ;
        }
        rep(i, nb){
            ll tm = ((n-i) % mod) * (modpow(b, mod-2));
            tm %= mod ;
            db *= tm ;
            db %= mod ;
            b-- ;
        }
        ll ans = modpow(2, n) - 1 - da - db  ;
        while(ans < 0){
            ans += mod ;
        }
        ans %= mod ;
        cout << ans << endl ;
    }