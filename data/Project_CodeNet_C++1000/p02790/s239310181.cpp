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
    
    ll a,b ; cin >> a >> b;
    
    ll ans = a > b ? a : b;
    ll prt = 0;
    if( ans == a )
        prt = b;
    else
        prt = a;
        
    for( ll i = 1 ; i <= ans ; i++ ) {
        cout << prt;
    }
    cout << "\n";
    
 return 0;
}
