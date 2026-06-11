//coded b vishal mourya - the legendary coder
#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define f(a,b) for(ll i = a ; i < b ; i++ )
#define fj(a,b) for(ll j = a ; j < b ; j++ )
#define fk(a,b) for(ll k = a ; k < b ; k++ )
#define fasthoja ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll highestPowerof2(ll n) { 
   ll p = (ll)log2(n); 
   return (ll)pow(2, p);  
} 

int main(void){
    fasthoja;
    
    ll h; cin >> h;
    if( h == 1 ) cout << "1\n";
    else {
//    	while( __builtin_popcount(h) != 1 ) {
//    		h--;	
//		}
		
		cout <<  highestPowerof2(h) * 2 - 1 << "\n";
	} 

 return 0;
}
