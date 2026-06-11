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
    vector<int> b (n - 1) ;
    rep(i, n - 1){
        cin >> b[i] ;
    }
    int ans = 0 ;
    int t = 100005;
    rep(i , n - 1){
        ans += min(t, b[i]) ;
        t = b[i] ;
    }
    ans += b[n - 2] ;
    cout << ans << endl ;
}