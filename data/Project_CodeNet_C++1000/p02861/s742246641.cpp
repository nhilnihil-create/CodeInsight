#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    cin >> n;
    vector<vector<int>>v(n,vector<int>(2));
    rep(i, n) cin >> v[i][0] >> v[i][1];
    double ans = 0;
    rep(i, n){
        rep(j, n){
            if (j == i) continue;
            ans += sqrt((v[i][0] - v[j][0])*(v[i][0] - v[j][0]) + (v[i][1] - v[j][1])*(v[i][1] - v[j][1]));
        
        }
    }
    ans /= n;
    cout << setprecision(15) << ans << endl;
    return 0;
}
