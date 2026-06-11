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
    string s; cin >> s;
    
    ll cnt = 0;
    ll limit = s.length();
    
    f( 0, limit) {
        if( s[i] == 'A' && ( i+1 < limit -1  ) && (i+2 <= limit - 1) ) {
            if( s[i+1] == 'B' && s[i+2] == 'C' )
                cnt++;
        }
    }
    
    cout << cnt << "\n";
 return 0;
}
