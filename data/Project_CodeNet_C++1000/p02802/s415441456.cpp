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
    
    ll n,m; cin >> n >> m;
    ll cac = 0, cwa = 0, cwat = 0;
    ll ans = 0;
    vec hero(n+1,0);
    vec cnt(n+1,0);
    hero[0] = 1;
    
    for( int i = 1 ; i <= m ; i++) {
        ll p1; cin >> p1;
        string st; cin >> st;
        
        // if( cac == n ) break;
        
        if( st == "WA" && hero[p1] == 0 ){
            //  cwat++;
            cnt[p1]++;
        }
        
        if( st == "AC" &&  hero[p1] != 1 ) {
            cac++;
            // if( cwa != 0 ) {
                
                hero[p1] = 1; //solved
                cwa += cnt[p1];
                // cwat = 0;
                
            // }
        }
        
        
    
    }
    
    cout << cac << " " << cwa << "\n";
    
 return 0;
}
