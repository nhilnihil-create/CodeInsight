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
    vector<int> w (n) ;
    rep(i, n) cin >> w[i] ;
    int res = 100000 ;
    for(int i = 1 ; i < n ; i++){
        int s1 = 0 ;
        int s2 = 0 ;
        rep(j, i){
            s1 += w[j] ;
        }
        for(int k = i ; k < n ; k++){
            s2 += w[k] ;
        }
        int t = abs(s1 - s2) ;
        res = min(res,t) ;
    }
    cout << res << endl ;
}