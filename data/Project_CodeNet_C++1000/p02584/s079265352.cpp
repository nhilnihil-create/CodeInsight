#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(ll i=0;i<n;i++)
#define mod 1000000007
#define oo 2000000000000000000LL
using namespace std;


void _sol(){
    ll x,k,d; cin >> x >> k >> d;
    x = abs(x);
    ll cnt = x/d;
    if( cnt > k ){
        cout << x - k*d;
    }
    else{
        if(cnt == k){
            cout << x - cnt*d;
        }
        else{
            x = x - cnt*d;
            k -= cnt;
            if(k%2){
                x = min( abs( x - d ) , abs(x+d) );
            }
            cout << x;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
