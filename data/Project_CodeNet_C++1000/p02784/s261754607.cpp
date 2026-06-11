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
    ll h; cin >> h;
    ll n; cin >> n;
    vec v(n);
    f(0,n) cin >> v[i];
    ll sum = 0;
    
    f(0,n) sum += v[i];
    
    if( sum >= h ) cout << "Yes\n";
    else cout << "No\n";

 return 0;
}
