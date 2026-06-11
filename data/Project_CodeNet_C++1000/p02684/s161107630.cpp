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
    ll k ;
    cin >> n >> k;
    vector<int> a (n) ;
    rep(i, n){
        cin >> a[i] ;
        a[i]-- ;
    }
    vector<int> loop ;
    vector<int> used (n) ;
    ll t = 0 ;
    while(1){
        if(used[t]){
            break ;
        }
        loop.push_back(t) ;
        used[t] = 1 ;
        t = a[t] ;
    }
    ll f = loop.size() ;
    ll num = 0 ; 
    rep(i, f){
        if(loop[i] == t){
            break ;
        }
        num++ ;
    }
    if(k < num){
        cout << loop[k] + 1 << endl ;
        return 0 ;
    }
    ll div = f - num ;
    k = (k - num) % div ;
    cout << loop[num + k] + 1 << endl ;
    return 0 ;
}  