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
    int n, x ;
    cin >> n >> x ;
    vector<int> d (n) ;
    rep(i, n) cin >> d[i] ;
    int t = 0;
    int res = 0 ;
    rep(i, n){
        t = t + d[i] ;
        res++ ;
        if(t > x){
            break ;
        }
        if(i == (n - 1)){
            res++ ;
        }
    }
    cout << res << endl ;
}