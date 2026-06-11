#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
vector<int> mx = {1,0,-1,0} ;
vector<int> my = {0, 1, 0, -1} ;


int main () {
    int n, k ;
    cin >> n >> k ;
    vector<double> p (n) ;
    rep(i, n) cin >> p[i] ;
    double mx = 0 ;
    int st = 0 ;
    double pos = 0 ;
    rep(i, k){
        pos += p[i] ;
    }
    rep(i, n - k + 1){
        if(i == 0) continue ;
        pos -= p[i - 1] ;
        pos += p[i + k - 1] ;
        if(pos > mx){
            mx = pos ;
            st = i ;
        }
    }
    double ans = 0 ;
    for(int i = st; i < st + k; i++){
        double sum = (1 + p[i])*p[i]/ 2 ;
        double f = sum * (1/p[i]) ;
        ans += f ;
    }
    cout << fixed << setprecision(10) ;
    cout << ans << endl ;
}