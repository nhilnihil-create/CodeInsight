#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    int n, q ;
    ll k ;
    cin >> n >> k >> q ;
    vector<int> a (q) ;
    vector<ll> ans (n) ;
    rep(i, q) {cin >> a[i] ;
    ans[a[i] - 1]++ ;}

    rep(i, n){
        if(k > q - ans[i]){
            cout << "Yes" << endl ;
        }
        else {
            cout << "No" << endl ;
        }
    }
    
}