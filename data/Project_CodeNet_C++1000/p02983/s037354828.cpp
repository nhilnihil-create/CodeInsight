#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    ll l,r;
    cin >> l >> r;
    if(r-l >= 2018){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1010101;
    for(ll i=l; i<r; i++){
        for(ll j=i+1; j<=r; j++){
            ll now;
            now = ((i%2019)*j)%2019; 
            ans = min(now,ans);
        }
    }
    cout << ans << endl;
    return 0;
}