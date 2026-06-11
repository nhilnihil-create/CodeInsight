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
    int n ;
    cin >> n ;
    vector<int> h (n) ;
    rep(i, n) cin >> h[i] ;
    vector<int> c (n) ;
    for(int i = n - 2; i >= 0; i--){
        if(h[i] >= h[i + 1]) c[i] = c[i + 1] + 1 ;
    }
    sort(c.begin(), c.end()) ;
    cout << c[n-1] << endl ;

}