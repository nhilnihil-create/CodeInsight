#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main () {
    int n ;
    cin >> n ;
    vector<P> b (n) ;
    map<int, int> a ;
    rep(i, n){
        int x, y ;
        cin >> x >> y ;
        b[i] = P(y, i) ;
        a[i] = x ; 
    }
    sort(b.begin(), b.end()) ;
    int tot = 0 ;
    rep(i, n){
        tot += a[b[i].second] ;
        if(tot > b[i].first) {
            cout << "No" << endl ;
            return 0 ;
        }
    }
    cout << "Yes" << endl ;
}

