//coded b vishal mourya - the legendary coder
#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define f(a,b) for(ll i = a ; i < b ; i++ )
#define fj(a,b) for(ll j = a ; j < b ; j++ )
#define fk(a,b) for(ll k = a ; k < b ; k++ )
#define fasthoja ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(void){
    fasthoja;
    
    ll n; cin >> n;
    
    ll a[10][10] = {0};
    
    for( ll i = 1 ; i <= n ; i++ ) {
        
        ll ld = i % 10;
        ll fd = 0;
        ll t1 = i;
        while( t1 > 0 ) {
            fd = t1 % 10;
            t1 /= 10;
        }
        // ll fd 
        
        a[fd][ld]++;
    }
    
    ll ans = 0;
    for( ll i = 0 ; i < 10 ; i++ ) {
        for( ll j = 0 ; j < 10 ; j++ ) {
            ans += ( a[i][j] * a[j][i] );
        }
    }
    cout << ans << "\n";
 return 0;
}
