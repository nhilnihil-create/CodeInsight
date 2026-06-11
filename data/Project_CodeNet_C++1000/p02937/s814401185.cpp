#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb insert
#define mod 998244353
set<ll> pos[30] ;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s ,t ;
    ll  n , m , i , j ;
    cin >> s >> t ;
    n = s.size() ;
    for (i = 0 ; i< n ; i ++) {
        pos[ s[i]-'a' ] .pb(i) ;
    }
    n = t.size() , m = s.size() ;
    ll ans = 0 , last = 0 ;
    for (i = 0 ; i< n ; i++) {
        ll x = t[i]-'a' ;
        auto y = pos[x].upper_bound(last-1) ;
        if (y==pos[x].end()) {
            ans+= (m-(last)) ;
           // cout << last << ' ' ;
            last = 0;
            y = pos[x].upper_bound(last-1) ; ;
            if (y == pos[x].end()) {
                cout << -1 << endl ;
                return 0 ;
            }
            ans+=(*y-(last)+1) ;
            last = *y +1;
        }
        else {
            ans+= (*y-(last)+1) ;
            last = *y+1 ;
        }
      //  cout<<ans << ' ' << last <<  endl ;

    }
    cout << ans << endl ;
    return 0 ;
}
