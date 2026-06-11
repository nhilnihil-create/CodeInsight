#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main () {
    ll r, l ;
    cin >> l >> r ;
    if(r - l > 3000){
        cout << 0 << endl ;
        return 0 ;
    }        
    ll ans = INF ;
    for(ll i = l; i <= r; i++){
        for(ll j = l; j <= r; j++){
            if(i >= j) continue ;
            ll t = (i%2019 * j%2019) % 2019 ;
            ans = min(ans, t) ;
        }
    }
    cout << ans << endl ;
}