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
    ll k; cin >> k;
    vec v(n);
    f(0,n) cin >> v[i];
    
    sort( v.rbegin() , v.rend() );
    
    if( k >= n ) cout << "0\n";
    else {
    	ll cnt = 0;
    	for( ll i = k ; i < v.size() ; i++ ) cnt += v[i];
    	cout << cnt << "\n";
	}

 return 0;
}
