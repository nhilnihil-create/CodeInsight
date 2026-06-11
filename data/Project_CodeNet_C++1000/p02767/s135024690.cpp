#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 
int main(){
    int n ;
    cin >> n ;
    vector<int> x (n) ;
    rep(i, n) cin >> x[i] ;
    ll ans = INF;
    for(int i = 1 ; i <= 100 ; i++){
        ll res = 0 ;
        rep(j, n){
            res += ((x[j] - i) * (x[j] - i)) ;
        }
        if(res < ans){
            ans = res ;
        }
    }
    cout << ans << endl ;
} 