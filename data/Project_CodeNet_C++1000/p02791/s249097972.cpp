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
    vec v(n);
    f(0,n) cin >> v[i];
    vec ans(n);
    ans[0] = v[0];
    // ll min = ans[0];
    f( 1,v.size() ) {
        if( v[i] < ans[i-1] ) {
            ans[i] = v[i];
        }
        else
            ans[i] = ans[i-1];
    }
    
    ll cnt = 0;
    f(0,n) {
        if( ans[i] == v[i] ) cnt++;
    }
    cout << cnt << "\n";
 return 0;
}
