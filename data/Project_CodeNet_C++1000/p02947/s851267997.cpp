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
    vector<string> s (n) ;
    rep(i, n){
        cin >> s[i] ;
    }
    rep(i, n){
        sort(s[i].begin(), s[i].end()) ;
    }
    sort(s.begin(), s.end()) ;
    string first = s[0] ;
    ll num = 0 ;
    ll ans = 0 ;
    rep(i, n){
        if(first == s[i]){
            num++ ;
        }
        else if(i != n -1) {
            first = s[i] ;
            ans += num*(num-1)/2 ;
            num = 1 ;
        }
        if(i == n -1) {
            ans += num*(num-1)/2 ;
        }
    }
    cout << ans << endl ;
} 
