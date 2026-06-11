#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        if(a[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1, div = INF;
    rep(i,n){
        if(div / a[i] == 0){
            cout << -1 << endl;
            return 0;
        }
        ans *= a[i];
        div = (div + a[i] - 1) / a[i];
    }
    if(ans > INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
