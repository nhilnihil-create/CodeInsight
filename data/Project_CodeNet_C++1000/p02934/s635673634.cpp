#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    int n ;
    cin >> n ;
    vector<double> a(n) ;
    rep(i, n){
        cin >> a[i] ;
    }
    double ans ; 
    double bunshi = 1;
    rep(i, n){
        bunshi *= a[i] ;
    }
    double bunbo = 0 ;
    rep(i, n){
        double kobun = 1 ;
        rep(j, n){
            if(i != j){
                kobun *= a[j] ;
            }
        }
        bunbo += kobun ;
    }
    ans = bunshi / bunbo ;
    cout << fixed << setprecision(8) ;
    cout << ans << endl ;
}