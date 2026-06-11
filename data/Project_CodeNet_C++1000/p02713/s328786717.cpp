#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 

int gcd (int x, int y){
    if(x % y == 0){
        return y ;
    }
    int k = x % y ; 
    return gcd(y, k) ;
}
int main(){
    int k ; 
    cin >> k ;
    ll ans = 0 ;
    for(int i = 1 ; i <= k ; i++){
        for(int j = 1 ; j <= k ; j++){
            for(int s = 1 ; s <= k ; s++){
                int f = gcd (i, j) ;
                int t = gcd (s, f) ;
                ans += t ;
            }
        }
    }
    cout << ans << endl ;
}