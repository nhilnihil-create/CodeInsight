#include <bits/stdc++.h>
#include <algorithm> 
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 

bool is_prime(double x){
    int  y = (int)(x) ;
    int  k = (int)(sqrt(x)) ;
    for(int i = 2 ; i <= k ; i++){
        if(y % i == 0 ){
            return false ; ;
        }
    }
    return true ; 
}

int main() {
    double ans ;
    cin >> ans ;
    while(1){
        if(is_prime(ans)){
            break ;
        }
        else {
            ans++ ;
        }
    }
    cout << ans << endl ;
    
}