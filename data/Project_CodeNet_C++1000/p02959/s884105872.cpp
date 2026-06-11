#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main () {
    ll n ;
    cin >> n ;
    vector<ll> a (n+1), b(n) ;
    rep(i, n+1) cin >> a[i] ;
    rep(i, n) cin >> b[i] ;
    ll ans = 0 ;
    rep(i, n){
        if(i == n -1){
            if(a[i] + a[i + 1] > b[i]){
                ans += b[i] ;
                break ;
            }
            else {
                ans += a[i] + a[i + 1] ;
                break ;
            }
        }
        if(a[i] <= b[i]){
            ans += a[i] ;
            if(a[i + 1] > (b[i] - a[i])){
                a[i + 1] -= (b[i] - a[i]) ;
                ans += (b[i] - a[i]) ;
            }
            else {
                ans += a[i + 1] ;
                a[i + 1] = 0 ;
            }
        }
        else {
            ans += b[i] ;
        }
    }
    cout << ans << endl ;
}