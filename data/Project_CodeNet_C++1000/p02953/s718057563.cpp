#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    int n ;
    cin >> n;
    vector<ll> h (n );
    rep(i, n){
        cin >> h[i] ;
    }
    bool ans = true ;
    ll lim = INF;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(h[i] > lim){
            h[i]-- ;
            if(h[i] > lim){
                ans = false ;
                break ;
            }
        }
        else {
            lim = h[i] ;
        }
    }
    
    if(ans){
        cout << "Yes" << endl ;
    }
    else{
        cout << "No" << endl ;
    }
} 
