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
    double n ;
    cin >> n ;
    vector<double> v (n) ;
    rep(i, n) cin >> v[i] ;
    sort(v.begin(), v.end()) ;
    rep(i, n -1){
        v[i + 1] = (v[i + 1] + v[i])/2 ;
    }
    cout << fixed << setprecision(10) ;
    cout << v[n - 1] << endl ;
}