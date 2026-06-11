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

int main (){
    int n ;
    cin >> n ;
    vector<int> a (n) ;
    vector<int> ans ;
    int tot = 0 ;
    int g = 0 ;
    rep(i, n) cin >> a[i] ;
    rep(i, n) tot += a[i] ;
    rep(i, n){
        if(i % 2 == 1){
            g += 2 * a[i] ;
        }
    }
    int x = tot - g ;
    int t = 0 ;
    while(t != n){
        ans.push_back(x) ;
        x = 2 * a[t] - x ;
        t++ ;
    }
    rep(i, ans.size()){
        cout << ans[i] << " " ;
    }
    cout << endl ;
}