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
    vector<int> a (n) ;
    vector<ll> b (200005) ;
    ll tot = 0 ;
    rep(i, n){
        cin >> a[i] ;
        b[a[i]]++ ;
    }
    rep(i, 200005){
        tot += (b[i] * (b[i] - 1))/ 2 ;
    }
    vector<ll> ans ;
    rep(i, n){
        ll t = b[a[i]] ;
        ll nw = tot - (t*(t - 1))/2 ;
        nw += (t-1)*(t-2)/2 ;
        ans.push_back(nw) ;
    }
    rep(i, n){
        cout << ans[i] << endl ;
    }
    return 0 ;
}  