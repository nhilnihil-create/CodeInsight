#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    int n ;
    cin >> n ;
    vector<double>  x (n) ;
    vector<double> y (n) ;
    vector<int> v (n) ;
    rep(i, n) {
        v[i] = i ; 
    }
    rep(i, n) {
        cin >> x[i] ; 
        cin >> y[i] ;
    }
    double tot = 0 ;
    do{
        rep(i, n){
            if(i == 0){
                continue ;
            }
            else {
                int e = v[i] ;
                int s = v[i - 1] ;
                tot += (sqrt(pow(x[e] - x[s], 2) + pow(y[e] - y[s], 2))) ;
            }
        }            
    }while(next_permutation(v.begin(),v.end())) ;
    double nn = n ;
    for(int i = 1; i < n ; i++){
        nn = nn * (n-i) ;
    }
    cout << fixed << setprecision(10) ;
    cout << tot / nn << endl ;
}