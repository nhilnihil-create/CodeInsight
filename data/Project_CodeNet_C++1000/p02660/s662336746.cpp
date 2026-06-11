#include <bits/stdc++.h>
#include <algorithm> 
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 

int main (){
    ll n ;
    cin >> n ;
    if(n == 1){
        cout << 0 << endl ;
        return 0 ;
    }
    ll k = ll(sqrt(double(n))) ;
    vector<bool> is_prime (k + 1, true) ;
    is_prime[0] = false ;
    is_prime[1] = false ; 
    rep(i, k + 1){
        if(is_prime[i]){
            for(int j = 2*i ; j <= k ; j += i){
                is_prime[j] = false ;
            }
        }
    }
    ll ans = 0 ;
    for(int i = 2 ; i <= k ; i++){
        if(n == 1){
            break ;
        }
        ll t = 0 ;
        if(is_prime[i]){
            while(n % i == 0){
                n /= i ;
                t++ ; 
            }
            ll p = 1 ;
            while(1){
                t -= p; 
                if(t < 0){
                    break ; 
                }
                ans++ ; 
                p++ ;
            }
        }
    }
    if(n != 1){
        ans++ ;
    }
    cout << ans << endl ;
    return 0 ;
}