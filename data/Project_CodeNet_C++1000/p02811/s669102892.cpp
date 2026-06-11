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
    ll k; cin >> k;
    ll x; cin >> x;
    
    ll hero = 500 * k;
    
    if( x <= hero ) cout << "Yes\n";
    else cout << "No\n";
 return 0;
}
