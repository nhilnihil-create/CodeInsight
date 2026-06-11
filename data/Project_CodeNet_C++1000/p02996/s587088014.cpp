#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i=0; i < (n); ++i)
using ll = long long ;
using namespace std;
const int INF = 1001001001;


int main() {

    int n ;
    cin >> n ;
    vector<pair<ll,ll>> a(n) ;

    rep(i,n){
        cin >> a[i].second >> a[i].first ;
    }
    sort(a.begin(),a.end()) ;

    ll sum = 0 ;
    rep(i,n){
        sum+=a[i].second ;
        if(sum>a[i].first){
            cout << "No" << endl ;
            return 0 ;
        }
        //cout << sum << endl ;
    }

    cout << "Yes" << endl ;
    return 0 ;
}
